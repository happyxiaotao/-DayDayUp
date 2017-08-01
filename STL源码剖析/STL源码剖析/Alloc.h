#pragma once

#ifndef _ALLOC_H_
#define _ALLOC_H_

#include <iostream>
#include <new.h>
using namespace std;


//一级空间适配器
template <int inst>
class _Malloc_Alloc_Template
{
private:

	typedef void(*pFun)();

	//oom：out of memroy，下面函数用来处理内部不足的情况
	static void *Oom_malloc(size_t);
	static void *Oom_realloc(void*, size_t);

	static pFun _Malloc_Alloc_Oom_Handler; //定义一个函数指针

public:
	static void* allocate(size_t n)
	{
		void* result = malloc(n);	//一级空间配置器慧姐使用malloc
		if (nullptr == result) 
			result = Oom_malloc(n);
		return result;
	}

	static void deallocate(void* p, size_t /* n */)
	{
		free(p); //一级空间配置器直接使用free
	}

	//一下函数仿真C++的set_new_handler()函数，即可以指定自己的out_of_memory handler
	static void (* )
};

#endif //_ALLOC_H_