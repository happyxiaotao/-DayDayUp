#pragma once

#include <iostream>
#include <string>

//#if 0
//#	include <new>
//#	define _THROW_BAD_ALLOC_ throw bad_alloc
//#elif !defined(_THROW_BAD_ALLOC_)
//#	include <iostream>
//#	define _THROW_BAD_ALLOC_ std::cerr << "out of memory"<<std::endl;exit(1);
//#endif


//定义函数指针
typedef void(*OOM_Handler)();

//一级空间配置器，申请或释放大块内存
template <int inst>
class Malloc_Alloc_Template
{
	//处理内存不够的函数
private:
	static void* OOM_Malloc(std::size_t);
	static void* OOM_Realloc(void*, std::size_t);
	static OOM_Handler _Malloc_Alloc_OOM_Handler; //_Malloc_Alloc_OOM_Handler是成员变量
public:
	static void* Allocate(std::size_t n)
	{
		void* res = malloc(n);
		//如果申请失败，调用用来处理内存不够的函数
		if (0 == res)
			res = OOM_Malloc(n);
		return res;
	}

	static void Dellocate(void* p, std::size_t size)
	{
		free(p);
	}

	static void* Reallocate(void* p, std::size_t odl_size, std::size_t new_size)
	{
		void* res = realloc(p, new_size);
		//如果内存不足以满足需求，调用OOM_Readlloc()函数
		if (0 == res)
			res = OOM_Realloc(p, new_size);
		return res;
	}

	//C++的set_new_handler函数，指定自己的out-of-memory handler
	static OOM_Handler Set_Malloc_Handler(OOM_Handler f)
	{
		OOM_Handler old = _Malloc_Alloc_OOM_Handler;
		_Malloc_Alloc_OOM_Handler = f;	//安装新的处理函数
		return old;		//返回旧的处理函数
	}
};

//静态成员在类外初始化
template <int inst>
OOM_Handler Malloc_Alloc_Template<inst>::_Malloc_Alloc_OOM_Handler = 0;

template <int inst>
void* Malloc_Alloc_Template<inst>::OOM_Malloc(std::size_t n)
{
	OOM_Handler My_Malloc_Handler;
	void* res = 0;
	for (;;)  //不断的尝试释放,配置内存
	{
		My_Malloc_Handler = _Malloc_Alloc_OOM_Handler;
		if (0 = My_Malloc_Handler)
		{
			_THROW_BAD_ALLOC_;
		}
		(My_Malloc_Handler)(); //调用自定义的内存释放函数，企图释放函数
		res = malloc(n); //再次尝试获取内存
		if (res)
			return res;
	}
}

template <int inst>
void* Malloc_Alloc_Template<inst>::OOM_Realloc(void*, std::size_t n)
{
	OOM_Handler My_Malloc_Handler;
	void* res = 0;
	for (;;)  //不断的尝试释放,配置内存
	{
		My_Malloc_Handler = _Malloc_Alloc_OOM_Handler;
		if (0 = My_Malloc_Handler)
		{
			_THROW_BAD_ALLOC_;
		}
		(My_Malloc_Handler)(); //调用自定义的内存释放函数，企图释放函数
		res = realloc(n); //再次尝试获取内存
		if (res)
			return res;
	}
}

//直接将参数inst指定为0
typedef Malloc_Alloc_Template<0> Malloc_Alloc;


//二级空间配置器
template <int inst>
class Default_Alloc_Template
{
private:
	enum {_ALIGN_ = 0}; //小型区块的上调边界
	enum {_MAX_BYTES_ = 128}; //小型区块的上限
	enum {_NFREELISTS_ = _MAX_BYTES_/_ALIGN_}; //free_list个数
	//将bytes上调到8的倍数
	static std::size_t ROUNG_UP(std::size_t bytes)
	{
		return ((bytes + _ALIGN_ - 1) & ~(_ALIGN_ + 1));
	}
	//根据bytes的大小，决定使用第n号自由链表。n从0开始
	static std::size_t FREELIST_INDEX(std::size_t bytes)
	{
		return ((bytes + _ALIGIN_ - 1) / _ALIGN_ - 1);
	}
	//自由链表，用来保存小块内存
	union Obj
	{
		Obj* _Free_List_Link;
		char _Client_Data[1];
	};
private:
	static Obj* volatile _Free_List[_NFREELISTS_]; //维护16个自由链表
	static char* _Start_Free;  //内存池起始位置，只在Chunk_ALloc()中改变
	static char* _End_Free;	//内存池结束位置，只在Chunk_ALloc()中改变
	static std::size_t _Heap_Size;	//使用堆的大小，

	//返回一个大小为n的对象，并可能加入大小为n的区块到自由链表中
	static void* Refill(std::size_t n);
	//配置一块空间，尽可能的给nobjs个size大小区块。如果不够，则会少给。
	static char* Chunk_Alloc(std::size_t size, int &nobjs);

public:
	static void* Allocate(std::size_t size);
	
	static void Deallocate(void* p, std::size_t n);

	static void* Reallocate(void* p, std::size_t old_size, std::size_t new_size);
};
//对静态成员变量赋值
template <int inst>
char* Default_Alloc_Template<inst>::_Start_Free = 0;

template <int inst>
char* Default_Alloc_Template<inst>::_End_Free = 0;

template <int inst>
char* Default_Alloc_Template<inst>::_Heap_Size = 0;

template <int inst>
Default_Alloc_Template<inst>::Obj* volatile Default_Alloc_Template<inst>::_Free_List[_NFREELISTS_] = { 0 };

//二级空间配置器，空间配置函数
//如果n大于128，就调用一级空间配置器
//否则检查n所对应的自由链表中是否还有可用的区块。如果有，就直接使用，如果没有，就调用Refill为自由链表填充
template <int inst>
void* Default_Alloc_Template<inst>::Allocate(std::size_t n)
{
	//大于128调用一级空间适配器
	if (n > 128)
	{
		return (Malloc_Alloc::Allocate(n));
	}
	std::size_t index = FREELIST_INDEX(n);
	//寻找16个自由链表中适当的一个
	Obj* result = _Free_List[index];
	
	if (0 == result)
	{	//没有找到可用的自由链表，调用Refill函数重新填充
		return Refill(ROUNG_UP(n));
	}
	//调整自由链表
	_Free_List[index] = result->_Free_List_Link;
	return result;
}

//二级空间适配器， 空间释放函数
//n大于128，则调用以及空间适配器的空间释放函数
//否则，找出对应的自由链表，将区块回收
template <int inst>
void Default_Alloc_Template<inst>::Deallocate(void* p, std::size_t n)
{
	//大于128调用一级空间适配器
	if (n > 128)
	{
		return Malloc_Alloc::Dellocate(p, n);
	}
	
	//寻找对应的自由链表
	std::size_t index = FREELIST_INDEX(n);
	(Obj*)p->_Free_List_Link = _Free_List[index];
	_Free_List[index] = (Obj*)p;
}

