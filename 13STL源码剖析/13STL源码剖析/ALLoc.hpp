#pragma once

#include <iostream>
#include <string>


#include <stdarg.h>

#define _DEBUG_
static std::string GetFileName(const std::string& path)
{
	char ch = '/';
#ifdef _WIN32
	ch = '\\';
#endif

	size_t pos = path.rfind(ch);
	if (pos == std::string::npos)
		return path;
	else
		return path.substr(pos + 1);
}

// 用于调试追踪的trace log
inline static void _trace_debug(const char * funcName,
	const char * fileName, int line, char* format, ...)
{
#ifdef _DEBUG_
	fprintf(stdout, "[%s:%d]%s", GetFileName(fileName).c_str(), line, funcName);

	// 输出用户信息
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
#endif
}

#define __TRACE_DEBUG(...) \
	_trace_debug(__FUNCDNAME__, __FILE__, __LINE__, __VA_ARGS__);



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
		__TRACE_DEBUG("一级空间配置器申请：%p-->%d\n", res, n);
		//如果申请失败，调用用来处理内存不够的函数
		if (nullptr == res)
			res = OOM_Malloc(n);
		return res;
	}

	static void Dellocate(void* p, std::size_t size)
	{
		__TRACE_DEBUG("一级空间配置器释放：%p-->%d\n", p, size);
		free(p);
	}

	static void* Reallocate(void* p, std::size_t odl_size, std::size_t new_size)
	{
		void* res = realloc(p, new_size);
		__TRACE_DEBUG("一级空间配置器申请：%p-->%d\n", p, size);
		//如果内存不足以满足需求，调用OOM_Readlloc()函数
		if (nullptr == res)
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
OOM_Handler Malloc_Alloc_Template<inst>::_Malloc_Alloc_OOM_Handler = nullptr;

template <int inst>
void* Malloc_Alloc_Template<inst>::OOM_Malloc(std::size_t n)
{
	__TRACE_DEBUG("系统空间不足，调用空间不足处理程序\n");
	OOM_Handler My_Malloc_Handler;
	void* res = nullptr;
	for (;;)  //不断的尝试释放,配置内存
	{
		My_Malloc_Handler = _Malloc_Alloc_OOM_Handler;
		if (nullptr == My_Malloc_Handler)
		{
			__TRACE_DEBUG("一级空间配置器，没有内存处理函数\n");
			exit(1);
		}
		(My_Malloc_Handler)(); //调用自定义的内存释放函数，企图释放函数
		res = malloc(n); //再次尝试获取内存
		__TRACE_DEBUG("一级空间配置器：%p-->%d\n", res, n);
		if (res)
			return res;
	}
}

template <int inst>
void* Malloc_Alloc_Template<inst>::OOM_Realloc(void*, std::size_t n)
{
	OOM_Handler My_Malloc_Handler;
	void* res = nullptr;
	for (;;)  //不断的尝试释放,配置内存
	{
		My_Malloc_Handler = _Malloc_Alloc_OOM_Handler;
		if (nullptr = My_Malloc_Handler)
		{
			_THROW_BAD_ALLOC_;
		}
		(My_Malloc_Handler)(); //调用自定义的内存释放函数，企图释放函数
		res = realloc(n); //再次尝试获取内存
		if (res)
			return res;
	}
}

//直接将参数inst指定为nullptr
typedef Malloc_Alloc_Template<0> Malloc_Alloc;


//二级空间配置器
template <int inst>
class Default_Alloc_Template
{
private:
	enum { _ALIGN_ = 8}; //小型区块的上调边界
	enum { _MAX_BYTES_ = 128}; //小型区块的上限
	enum { _NFREELISTS_ = _MAX_BYTES_/_ALIGN_}; //free_list个数
	//将bytes上调到8的倍数
	static std::size_t ROUNG_UP(std::size_t bytes)
	{
		return ((bytes + _ALIGN_ - 1) & ~(_ALIGN_ - 1));
	}
	//根据bytes的大小，决定使用第n号自由链表。n从nullptr开始
	static std::size_t FREELIST_INDEX(std::size_t bytes)
	{
		return ((bytes + _ALIGN_ - 1) / _ALIGN_ - 1);
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
	static void* Chunk_Alloc(std::size_t size, std::size_t &nobjs);

public:
	static void* Allocate(std::size_t size);
	
	static void Deallocate(void* p, std::size_t n);

	static void* Reallocate(void* p, std::size_t old_size, std::size_t new_size);
};
//对静态成员变量赋值
template <int inst>
char* Default_Alloc_Template<inst>::_Start_Free = nullptr;

template <int inst>
char* Default_Alloc_Template<inst>::_End_Free = nullptr;

template <int inst>
std::size_t Default_Alloc_Template<inst>::_Heap_Size = 0;

template <int inst>
typename Default_Alloc_Template<inst>::Obj* volatile Default_Alloc_Template<inst>::_Free_List[_NFREELISTS_] = { nullptr };

//二级空间配置器，空间配置函数
//如果n大于128，就调用一级空间配置器
//否则检查n所对应的自由链表中是否还有可用的区块。如果有，就直接使用，如果没有，就调用Refill为自由链表填充
template <int inst>
void* Default_Alloc_Template<inst>::Allocate(std::size_t n)
{
	__TRACE_DEBUG("二级空间配置器将要申请%d大小的空间\n", n);
	//大于128调用一级空间适配器
	if (n > _MAX_BYTES_)
	{
		__TRACE_DEBUG("内存请求大于128：调用二级空间配置器\n");
		return (Malloc_Alloc::Allocate(n));
	}
	std::size_t index = FREELIST_INDEX(n);
	//寻找16个自由链表中适当的一个
	Obj* res = _Free_List[index];
	
	if (nullptr == res)
	{	
		__TRACE_DEBUG("二级空间配置器申请：freeList[%d]没有可用的小块内存\n", index);
		//没有找到可用的自由链表，调用Refill函数重新填充
		return Refill(ROUNG_UP(n));
	}
	//调整自由链表
	_Free_List[index] = res->_Free_List_Link;
	__TRACE_DEBUG("二级空间配置器申请：freeList[%d]:%d--->%p\n", index, n, res);
	return res;
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
		return Malloc_Alloc::Dellocate(p, n);  //Malloc_Alloc是一级空间配置器
	}
	
	//寻找对应的自由链表
	std::size_t index = FREELIST_INDEX(n);
	(Obj*)p->_Free_List_Link = _Free_List[index]; //注意把指针类型强转
	_Free_List[index] = (Obj*)p;
}

//重新填充函数
template <int inst>
void* Default_Alloc_Template<inst>::Refill(std::size_t size)
{
	std::size_t nObjs = 20; //初始要求20个
	__TRACE_DEBUG("二级空间配置器申请：ChunkAlloc：%d个%d字节的小块内存\n", nObjs, size);
	char* chunk = (char*)Chunk_Alloc(size, nObjs); //nObjs作为一个引用参数传递

	if (1 == nObjs)
	{
		__TRACE_DEBUG("二级空间配置器申请：ChunkAlloc：1个%d字节的小块内存\n", size);
		return chunk;
	}

	std::size_t index = FREELIST_INDEX(size);

	__TRACE_DEBUG("二级空间配置器申请：ChunkAlloc：%d个%d字节的小块内存\n", nObjs, size);
	__TRACE_DEBUG("二级空间配置器申请：第一块交给用户，%d小块内存挂到freeList[%d]:%d\n", nObjs - 1, index, (index + 1)*_ALIGN_);

	void* res = (char*)chunk;

	for (std::size_t i = 1; i < nObjs; i++)
	{
		chunk += size;
		((Obj*)chunk)->_Free_List_Link = _Free_List[index];
		_Free_List[index] = (Obj*)chunk;
	}

	return res;
}

//分配若干个大小为size的连续内存区域并返回起始地址chunk和成功分配的块数n 
template <int inst>
void* Default_Alloc_Template<inst>::Chunk_Alloc(std::size_t size, std::size_t& n)
{
	std::size_t total_bytes = n*size; //要求的内存
	std::size_t left_bytes = _End_Free - _Start_Free; //剩余内存

	if (left_bytes >= total_bytes)//如果剩余内存足够
	{
		__TRACE_DEBUG("内存池可以提供%d个%d大小的内存块\n", n, size);

		void *res = _Start_Free;
		_Start_Free += total_bytes;
		return res;
	}
	else if (left_bytes >= size)  //如果剩余内存不够2nullptr个size，能给多少给多少
	{
		n = left_bytes / size;

		__TRACE_DEBUG("内存池可以提供%d个小块内存\n", n);

		void *res = _Start_Free;
		_Start_Free += n*size;
		return res;
	}
	else  //内存池中剩余不够一个size大小内存
	{
		__TRACE_DEBUG("内存池空间不够一个%d大小\n", size);
		//如果剩余内存大于nullptr，则先放到对应的自由链表中
		if (left_bytes > 0)
		{
			__TRACE_DEBUG("将内存池中剩余空间放入自由链表中\n");
			std::size_t index = FREELIST_INDEX(left_bytes);
			((Obj*)_Start_Free)->_Free_List_Link = _Free_List[index];
			_Free_List[index] = (Obj*)_Start_Free;
		}

		//内存池向系统中获取空间
		std::size_t get_2bytes = 2 * total_bytes + ROUNG_UP(_Heap_Size >> 4);

		_Start_Free = (char*)malloc(get_2bytes);
		
		//系统中没有足够使用的空间
		if (nullptr == _Start_Free)
		{
			__TRACE_DEBUG("在自由链表中寻找空间\n");
			//采取在自由链表中寻找更大的空间
			std::size_t index = FREELIST_INDEX(size);
			for (; index < _MAX_BYTES_ / _ALIGN_; index++)
			{
				//如果存在自由链表不为空
				if (_Free_List[index])
				{
					__TRACE_DEBUG("自由链表有更大的空间freeList[%d]:%d\n", index, (index + 1)*_ALIGN_);
					_Start_Free = (char*)_Free_List[index];  //_Start_Free指向较大的自由链表
					_Free_List[index] = _Free_List[index]->_Free_List_Link;  //更新_Free_List[index]指向
					_End_Free = _Start_Free + (index + 1)*_ALIGN_; //更新_End_Free

					return Chunk_Alloc(size, n);  //分配好空间后，递归调用自己，重新开始计算。
				}
			}

			_End_Free = nullptr; //为了防止Malloc_Alloc::Allocate(get_2bytes);申请失败，提起将_End_Free置为nullptr处理

			__TRACE_DEBUG("自由链表没有更大的空间，到一级空间配置器中看\n");
			//在自由链表中也找不到多余的空间了
			//在一级空间适配器中试试
			_Start_Free = (char*)Malloc_Alloc::Allocate(get_2bytes);
		}
		//走到这里，说明内存已经获得
		_Heap_Size += get_2bytes;
		_End_Free = _Start_Free + get_2bytes;
	}

	return Chunk_Alloc(size, n);
}

//设置默认使用的空间配置器
#ifdef USE_MALLOC
typedef Malloc_Alloc _Alloc;
#else
typedef Default_Alloc_Template<0> _Alloc;
#endif


//设置通用空间适配器模板
template <typename T, typename Alloc>
class Simple_Alloc
{
public:
	//带参数，申请n*sizeof(T)大小空间
	static T* Allocate(void)
	{
		return (T*)Alloc::Allocate(sizeof(T));
	}
	//不带参数，申请sizeof(T)大小空间
	static T* Allocate(std::size_t n)
	{
		return (0 == n) ? nullptr : (T*)Alloc::Allocate(n*sizeof(T));
	}
	//释放空间
	static void DeAllocate(T* p)
	{
		if (p)
		{
			Alloc::DeAllocate(p, sizeof(T));
		}
	}
	//释放空间
	static void DeAllocate(T* p, std::size_t n)
	{
		if (p)
		{
			Alloc::DeAllocate(p, n*sizeof(T));
		}
	}
};