#pragma once

#ifndef _ALLOC_H_
#define _ALLOC_H_

#include <iostream>
#include <new.h>
using namespace std;


//һ���ռ�������
template <int inst>
class _Malloc_Alloc_Template
{
private:

	typedef void(*pFun)();

	//oom��out of memroy�����溯�����������ڲ���������
	static void *Oom_malloc(size_t);
	static void *Oom_realloc(void*, size_t);

	static pFun _Malloc_Alloc_Oom_Handler; //����һ������ָ��

public:
	static void* allocate(size_t n)
	{
		void* result = malloc(n);	//һ���ռ��������۽�ʹ��malloc
		if (nullptr == result) 
			result = Oom_malloc(n);
		return result;
	}

	static void deallocate(void* p, size_t /* n */)
	{
		free(p); //һ���ռ�������ֱ��ʹ��free
	}

	//һ�º�������C++��set_new_handler()������������ָ���Լ���out_of_memory handler
	static void (* )
};

#endif //_ALLOC_H_