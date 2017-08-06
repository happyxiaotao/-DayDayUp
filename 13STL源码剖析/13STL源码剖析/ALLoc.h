#pragma once

#include <iostream>
#include <string>

//定义函数指针
typedef void(*OOMHandle)();

//一级空间配置器，申请或释放大块内存
template <int inst>
class MallocAllocTemplate
{
public:
	static void* Allocate(size_t n)
	{
		void* res = malloc(n);

		//如果申请失败，调用用来处理内存不够的函数
		if (NULL == res)
			return OOM_Malloc(n);

		return res;
	}

	static void Dellocate(void* p, siez_t size)
	{
		free(p);
	}
};