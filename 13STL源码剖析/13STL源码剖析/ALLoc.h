#pragma once

#include <iostream>
#include <string>

//���庯��ָ��
typedef void(*OOMHandle)();

//һ���ռ���������������ͷŴ���ڴ�
template <int inst>
class MallocAllocTemplate
{
public:
	static void* Allocate(size_t n)
	{
		void* res = malloc(n);

		//�������ʧ�ܣ��������������ڴ治���ĺ���
		if (NULL == res)
			return OOM_Malloc(n);

		return res;
	}

	static void Dellocate(void* p, siez_t size)
	{
		free(p);
	}
};