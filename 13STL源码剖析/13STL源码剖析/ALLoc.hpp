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

// ���ڵ���׷�ٵ�trace log
inline static void _trace_debug(const char * funcName,
	const char * fileName, int line, char* format, ...)
{
#ifdef _DEBUG_
	fprintf(stdout, "[%s:%d]%s", GetFileName(fileName).c_str(), line, funcName);

	// ����û���Ϣ
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
#endif
}

#define __TRACE_DEBUG(...) \
	_trace_debug(__FUNCDNAME__, __FILE__, __LINE__, __VA_ARGS__);



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
		__TRACE_DEBUG("һ���ռ����������룺%p-->%d\n", res, n);
		//�������ʧ�ܣ��������������ڴ治���ĺ���
		if (nullptr == res)
			res = OOM_Malloc(n);
		return res;
	}

	static void Dellocate(void* p, std::size_t size)
	{
		__TRACE_DEBUG("һ���ռ��������ͷţ�%p-->%d\n", p, size);
		free(p);
	}

	static void* Reallocate(void* p, std::size_t odl_size, std::size_t new_size)
	{
		void* res = realloc(p, new_size);
		__TRACE_DEBUG("һ���ռ����������룺%p-->%d\n", p, size);
		//����ڴ治�����������󣬵���OOM_Readlloc()����
		if (nullptr == res)
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
OOM_Handler Malloc_Alloc_Template<inst>::_Malloc_Alloc_OOM_Handler = nullptr;

template <int inst>
void* Malloc_Alloc_Template<inst>::OOM_Malloc(std::size_t n)
{
	__TRACE_DEBUG("ϵͳ�ռ䲻�㣬���ÿռ䲻�㴦�����\n");
	OOM_Handler My_Malloc_Handler;
	void* res = nullptr;
	for (;;)  //���ϵĳ����ͷ�,�����ڴ�
	{
		My_Malloc_Handler = _Malloc_Alloc_OOM_Handler;
		if (nullptr == My_Malloc_Handler)
		{
			__TRACE_DEBUG("һ���ռ���������û���ڴ洦����\n");
			exit(1);
		}
		(My_Malloc_Handler)(); //�����Զ�����ڴ��ͷź�������ͼ�ͷź���
		res = malloc(n); //�ٴγ��Ի�ȡ�ڴ�
		__TRACE_DEBUG("һ���ռ���������%p-->%d\n", res, n);
		if (res)
			return res;
	}
}

template <int inst>
void* Malloc_Alloc_Template<inst>::OOM_Realloc(void*, std::size_t n)
{
	OOM_Handler My_Malloc_Handler;
	void* res = nullptr;
	for (;;)  //���ϵĳ����ͷ�,�����ڴ�
	{
		My_Malloc_Handler = _Malloc_Alloc_OOM_Handler;
		if (nullptr = My_Malloc_Handler)
		{
			_THROW_BAD_ALLOC_;
		}
		(My_Malloc_Handler)(); //�����Զ�����ڴ��ͷź�������ͼ�ͷź���
		res = realloc(n); //�ٴγ��Ի�ȡ�ڴ�
		if (res)
			return res;
	}
}

//ֱ�ӽ�����instָ��Ϊnullptr
typedef Malloc_Alloc_Template<0> Malloc_Alloc;


//�����ռ�������
template <int inst>
class Default_Alloc_Template
{
private:
	enum { _ALIGN_ = 8}; //С��������ϵ��߽�
	enum { _MAX_BYTES_ = 128}; //С�����������
	enum { _NFREELISTS_ = _MAX_BYTES_/_ALIGN_}; //free_list����
	//��bytes�ϵ���8�ı���
	static std::size_t ROUNG_UP(std::size_t bytes)
	{
		return ((bytes + _ALIGN_ - 1) & ~(_ALIGN_ - 1));
	}
	//����bytes�Ĵ�С������ʹ�õ�n����������n��nullptr��ʼ
	static std::size_t FREELIST_INDEX(std::size_t bytes)
	{
		return ((bytes + _ALIGN_ - 1) / _ALIGN_ - 1);
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
	static void* Chunk_Alloc(std::size_t size, std::size_t &nobjs);

public:
	static void* Allocate(std::size_t size);
	
	static void Deallocate(void* p, std::size_t n);

	static void* Reallocate(void* p, std::size_t old_size, std::size_t new_size);
};
//�Ծ�̬��Ա������ֵ
template <int inst>
char* Default_Alloc_Template<inst>::_Start_Free = nullptr;

template <int inst>
char* Default_Alloc_Template<inst>::_End_Free = nullptr;

template <int inst>
std::size_t Default_Alloc_Template<inst>::_Heap_Size = 0;

template <int inst>
typename Default_Alloc_Template<inst>::Obj* volatile Default_Alloc_Template<inst>::_Free_List[_NFREELISTS_] = { nullptr };

//�����ռ����������ռ����ú���
//���n����128���͵���һ���ռ�������
//������n����Ӧ�������������Ƿ��п��õ����顣����У���ֱ��ʹ�ã����û�У��͵���RefillΪ�����������
template <int inst>
void* Default_Alloc_Template<inst>::Allocate(std::size_t n)
{
	__TRACE_DEBUG("�����ռ���������Ҫ����%d��С�Ŀռ�\n", n);
	//����128����һ���ռ�������
	if (n > _MAX_BYTES_)
	{
		__TRACE_DEBUG("�ڴ��������128�����ö����ռ�������\n");
		return (Malloc_Alloc::Allocate(n));
	}
	std::size_t index = FREELIST_INDEX(n);
	//Ѱ��16�������������ʵ���һ��
	Obj* res = _Free_List[index];
	
	if (nullptr == res)
	{	
		__TRACE_DEBUG("�����ռ����������룺freeList[%d]û�п��õ�С���ڴ�\n", index);
		//û���ҵ����õ�������������Refill�����������
		return Refill(ROUNG_UP(n));
	}
	//������������
	_Free_List[index] = res->_Free_List_Link;
	__TRACE_DEBUG("�����ռ����������룺freeList[%d]:%d--->%p\n", index, n, res);
	return res;
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
		return Malloc_Alloc::Dellocate(p, n);  //Malloc_Alloc��һ���ռ�������
	}
	
	//Ѱ�Ҷ�Ӧ����������
	std::size_t index = FREELIST_INDEX(n);
	(Obj*)p->_Free_List_Link = _Free_List[index]; //ע���ָ������ǿת
	_Free_List[index] = (Obj*)p;
}

//������亯��
template <int inst>
void* Default_Alloc_Template<inst>::Refill(std::size_t size)
{
	std::size_t nObjs = 20; //��ʼҪ��20��
	__TRACE_DEBUG("�����ռ����������룺ChunkAlloc��%d��%d�ֽڵ�С���ڴ�\n", nObjs, size);
	char* chunk = (char*)Chunk_Alloc(size, nObjs); //nObjs��Ϊһ�����ò�������

	if (1 == nObjs)
	{
		__TRACE_DEBUG("�����ռ����������룺ChunkAlloc��1��%d�ֽڵ�С���ڴ�\n", size);
		return chunk;
	}

	std::size_t index = FREELIST_INDEX(size);

	__TRACE_DEBUG("�����ռ����������룺ChunkAlloc��%d��%d�ֽڵ�С���ڴ�\n", nObjs, size);
	__TRACE_DEBUG("�����ռ����������룺��һ�齻���û���%dС���ڴ�ҵ�freeList[%d]:%d\n", nObjs - 1, index, (index + 1)*_ALIGN_);

	void* res = (char*)chunk;

	for (std::size_t i = 1; i < nObjs; i++)
	{
		chunk += size;
		((Obj*)chunk)->_Free_List_Link = _Free_List[index];
		_Free_List[index] = (Obj*)chunk;
	}

	return res;
}

//�������ɸ���СΪsize�������ڴ����򲢷�����ʼ��ַchunk�ͳɹ�����Ŀ���n 
template <int inst>
void* Default_Alloc_Template<inst>::Chunk_Alloc(std::size_t size, std::size_t& n)
{
	std::size_t total_bytes = n*size; //Ҫ����ڴ�
	std::size_t left_bytes = _End_Free - _Start_Free; //ʣ���ڴ�

	if (left_bytes >= total_bytes)//���ʣ���ڴ��㹻
	{
		__TRACE_DEBUG("�ڴ�ؿ����ṩ%d��%d��С���ڴ��\n", n, size);

		void *res = _Start_Free;
		_Start_Free += total_bytes;
		return res;
	}
	else if (left_bytes >= size)  //���ʣ���ڴ治��2nullptr��size���ܸ����ٸ�����
	{
		n = left_bytes / size;

		__TRACE_DEBUG("�ڴ�ؿ����ṩ%d��С���ڴ�\n", n);

		void *res = _Start_Free;
		_Start_Free += n*size;
		return res;
	}
	else  //�ڴ����ʣ�಻��һ��size��С�ڴ�
	{
		__TRACE_DEBUG("�ڴ�ؿռ䲻��һ��%d��С\n", size);
		//���ʣ���ڴ����nullptr�����ȷŵ���Ӧ������������
		if (left_bytes > 0)
		{
			__TRACE_DEBUG("���ڴ����ʣ��ռ��������������\n");
			std::size_t index = FREELIST_INDEX(left_bytes);
			((Obj*)_Start_Free)->_Free_List_Link = _Free_List[index];
			_Free_List[index] = (Obj*)_Start_Free;
		}

		//�ڴ����ϵͳ�л�ȡ�ռ�
		std::size_t get_2bytes = 2 * total_bytes + ROUNG_UP(_Heap_Size >> 4);

		_Start_Free = (char*)malloc(get_2bytes);
		
		//ϵͳ��û���㹻ʹ�õĿռ�
		if (nullptr == _Start_Free)
		{
			__TRACE_DEBUG("������������Ѱ�ҿռ�\n");
			//��ȡ������������Ѱ�Ҹ���Ŀռ�
			std::size_t index = FREELIST_INDEX(size);
			for (; index < _MAX_BYTES_ / _ALIGN_; index++)
			{
				//���������������Ϊ��
				if (_Free_List[index])
				{
					__TRACE_DEBUG("���������и���Ŀռ�freeList[%d]:%d\n", index, (index + 1)*_ALIGN_);
					_Start_Free = (char*)_Free_List[index];  //_Start_Freeָ��ϴ����������
					_Free_List[index] = _Free_List[index]->_Free_List_Link;  //����_Free_List[index]ָ��
					_End_Free = _Start_Free + (index + 1)*_ALIGN_; //����_End_Free

					return Chunk_Alloc(size, n);  //����ÿռ�󣬵ݹ�����Լ������¿�ʼ���㡣
				}
			}

			_End_Free = nullptr; //Ϊ�˷�ֹMalloc_Alloc::Allocate(get_2bytes);����ʧ�ܣ�����_End_Free��Ϊnullptr����

			__TRACE_DEBUG("��������û�и���Ŀռ䣬��һ���ռ��������п�\n");
			//������������Ҳ�Ҳ�������Ŀռ���
			//��һ���ռ�������������
			_Start_Free = (char*)Malloc_Alloc::Allocate(get_2bytes);
		}
		//�ߵ����˵���ڴ��Ѿ����
		_Heap_Size += get_2bytes;
		_End_Free = _Start_Free + get_2bytes;
	}

	return Chunk_Alloc(size, n);
}

//����Ĭ��ʹ�õĿռ�������
#ifdef USE_MALLOC
typedef Malloc_Alloc _Alloc;
#else
typedef Default_Alloc_Template<0> _Alloc;
#endif


//����ͨ�ÿռ�������ģ��
template <typename T, typename Alloc>
class Simple_Alloc
{
public:
	//������������n*sizeof(T)��С�ռ�
	static T* Allocate(void)
	{
		return (T*)Alloc::Allocate(sizeof(T));
	}
	//��������������sizeof(T)��С�ռ�
	static T* Allocate(std::size_t n)
	{
		return (0 == n) ? nullptr : (T*)Alloc::Allocate(n*sizeof(T));
	}
	//�ͷſռ�
	static void DeAllocate(T* p)
	{
		if (p)
		{
			Alloc::DeAllocate(p, sizeof(T));
		}
	}
	//�ͷſռ�
	static void DeAllocate(T* p, std::size_t n)
	{
		if (p)
		{
			Alloc::DeAllocate(p, n*sizeof(T));
		}
	}
};