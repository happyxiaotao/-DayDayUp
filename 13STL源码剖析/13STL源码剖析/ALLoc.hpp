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


//���庯��ָ��
typedef void(*OOM_Handler)();

//һ���ռ���������������ͷŴ���ڴ�
template <int inst>
class Malloc_Alloc_Template
{
	//�����ڴ治���ĺ���
private:
	static void* OOM_Malloc(std::size_t);
	static void* OOM_Realloc(void*, std::size_t);
	static OOM_Handler _Malloc_Alloc_OOM_Handler; //_Malloc_Alloc_OOM_Handler�ǳ�Ա����
public:
	static void* Allocate(std::size_t n)
	{
		void* res = malloc(n);
		//�������ʧ�ܣ��������������ڴ治���ĺ���
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
		//����ڴ治�����������󣬵���OOM_Readlloc()����
		if (0 == res)
			res = OOM_Realloc(p, new_size);
		return res;
	}

	//C++��set_new_handler������ָ���Լ���out-of-memory handler
	static OOM_Handler Set_Malloc_Handler(OOM_Handler f)
	{
		OOM_Handler old = _Malloc_Alloc_OOM_Handler;
		_Malloc_Alloc_OOM_Handler = f;	//��װ�µĴ�����
		return old;		//���ؾɵĴ�����
	}
};

//��̬��Ա�������ʼ��
template <int inst>
OOM_Handler Malloc_Alloc_Template<inst>::_Malloc_Alloc_OOM_Handler = 0;

template <int inst>
void* Malloc_Alloc_Template<inst>::OOM_Malloc(std::size_t n)
{
	OOM_Handler My_Malloc_Handler;
	void* res = 0;
	for (;;)  //���ϵĳ����ͷ�,�����ڴ�
	{
		My_Malloc_Handler = _Malloc_Alloc_OOM_Handler;
		if (0 = My_Malloc_Handler)
		{
			_THROW_BAD_ALLOC_;
		}
		(My_Malloc_Handler)(); //�����Զ�����ڴ��ͷź�������ͼ�ͷź���
		res = malloc(n); //�ٴγ��Ի�ȡ�ڴ�
		if (res)
			return res;
	}
}

template <int inst>
void* Malloc_Alloc_Template<inst>::OOM_Realloc(void*, std::size_t n)
{
	OOM_Handler My_Malloc_Handler;
	void* res = 0;
	for (;;)  //���ϵĳ����ͷ�,�����ڴ�
	{
		My_Malloc_Handler = _Malloc_Alloc_OOM_Handler;
		if (0 = My_Malloc_Handler)
		{
			_THROW_BAD_ALLOC_;
		}
		(My_Malloc_Handler)(); //�����Զ�����ڴ��ͷź�������ͼ�ͷź���
		res = realloc(n); //�ٴγ��Ի�ȡ�ڴ�
		if (res)
			return res;
	}
}

//ֱ�ӽ�����instָ��Ϊ0
typedef Malloc_Alloc_Template<0> Malloc_Alloc;


//�����ռ�������
template <int inst>
class Default_Alloc_Template
{
private:
	enum {_ALIGN_ = 0}; //С��������ϵ��߽�
	enum {_MAX_BYTES_ = 128}; //С�����������
	enum {_NFREELISTS_ = _MAX_BYTES_/_ALIGN_}; //free_list����
	//��bytes�ϵ���8�ı���
	static std::size_t ROUNG_UP(std::size_t bytes)
	{
		return ((bytes + _ALIGN_ - 1) & ~(_ALIGN_ + 1));
	}
	//����bytes�Ĵ�С������ʹ�õ�n����������n��0��ʼ
	static std::size_t FREELIST_INDEX(std::size_t bytes)
	{
		return ((bytes + _ALIGIN_ - 1) / _ALIGN_ - 1);
	}
	//����������������С���ڴ�
	union Obj
	{
		Obj* _Free_List_Link;
		char _Client_Data[1];
	};
private:
	static Obj* volatile _Free_List[_NFREELISTS_]; //ά��16����������
	static char* _Start_Free;  //�ڴ����ʼλ�ã�ֻ��Chunk_ALloc()�иı�
	static char* _End_Free;	//�ڴ�ؽ���λ�ã�ֻ��Chunk_ALloc()�иı�
	static std::size_t _Heap_Size;	//ʹ�öѵĴ�С��

	//����һ����СΪn�Ķ��󣬲����ܼ����СΪn�����鵽����������
	static void* Refill(std::size_t n);
	//����һ��ռ䣬�����ܵĸ�nobjs��size��С���顣�������������ٸ���
	static char* Chunk_Alloc(std::size_t size, int &nobjs);

public:
	static void* Allocate(std::size_t size);
	
	static void Deallocate(void* p, std::size_t n);

	static void* Reallocate(void* p, std::size_t old_size, std::size_t new_size);
};
//�Ծ�̬��Ա������ֵ
template <int inst>
char* Default_Alloc_Template<inst>::_Start_Free = 0;

template <int inst>
char* Default_Alloc_Template<inst>::_End_Free = 0;

template <int inst>
char* Default_Alloc_Template<inst>::_Heap_Size = 0;

template <int inst>
Default_Alloc_Template<inst>::Obj* volatile Default_Alloc_Template<inst>::_Free_List[_NFREELISTS_] = { 0 };

//�����ռ����������ռ����ú���
//���n����128���͵���һ���ռ�������
//������n����Ӧ�������������Ƿ��п��õ����顣����У���ֱ��ʹ�ã����û�У��͵���RefillΪ�����������
template <int inst>
void* Default_Alloc_Template<inst>::Allocate(std::size_t n)
{
	//����128����һ���ռ�������
	if (n > 128)
	{
		return (Malloc_Alloc::Allocate(n));
	}
	std::size_t index = FREELIST_INDEX(n);
	//Ѱ��16�������������ʵ���һ��
	Obj* result = _Free_List[index];
	
	if (0 == result)
	{	//û���ҵ����õ�������������Refill�����������
		return Refill(ROUNG_UP(n));
	}
	//������������
	_Free_List[index] = result->_Free_List_Link;
	return result;
}

//�����ռ��������� �ռ��ͷź���
//n����128��������Լ��ռ��������Ŀռ��ͷź���
//�����ҳ���Ӧ�������������������
template <int inst>
void Default_Alloc_Template<inst>::Deallocate(void* p, std::size_t n)
{
	//����128����һ���ռ�������
	if (n > 128)
	{
		return Malloc_Alloc::Dellocate(p, n);
	}
	
	//Ѱ�Ҷ�Ӧ����������
	std::size_t index = FREELIST_INDEX(n);
	(Obj*)p->_Free_List_Link = _Free_List[index];
	_Free_List[index] = (Obj*)p;
}

