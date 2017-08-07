#pragma once
#include <assert.h>


/*
��������
���ų�������������-->O��N��
���������ݵ���-->O��N^2��
�ȶ�

��Ӧ�ĳ�����������С�����ݽӽ�����

Q�����������ҵ����ݣ������ò��������˼������
A��ÿ��ĳ�����������ݿ�����һ���������gap=3�����������ݽ��в������򡣴�ʱ�������Լ��ӽ������ˡ�
�ڽ�����֮��ļ������1�����ڽ��з��飬���ҽ��в��������������ݻ�Խ��Խ���򡣲��������Ч�ʸ��ߡ�
*/

//ԭ��
//ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O��1��
void InsertSort(int* array, int size)
{
	assert(nullptr != array);
	assert(size > 0);

	for (int idx = 1; idx < size; idx++)
	{
		int key = array[idx];
		int end = idx - 1;

		while (end >= 0 && array[end] > key)
		{
			array[end + 1] = array[end];
			end--;
		}

		array[end + 1] = key;
	}
}

//�Ż�������ѭ���ڵıȽϴ���
//���ö��ֲ���ֱ���ҵ�������λ��
void InsertSort_Optimize(int* array, int size)
{
	assert(nullptr != array);
	assert(size > 0);

	for (int idx = 1; idx < size; idx++)
	{
		int key = array[idx];
		int end = idx - 1;

		int left = 0;
		int right = end;

		//�Ƚϴ��� O��log2N��
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (array[mid] > key)
				right = mid - 1;
			else
				left = mid + 1;
		}

		//left����洢λ��
		while (end >= left)
		{
			array[end + 1] = array[end];
			end--;
		}

		array[end + 1] = key;
	}
}