#pragma once

#include <cassert>
/*
冒泡排序
思想:通过与相邻元素的比较和交换,把最小的元素冒泡到顶端

	外循环size-1次
	内循环size-1-i;

时间复杂度：O（2^N）
空间复杂度：O（1）
稳定性：稳定

*/

void BubbleSort(int* arr, int size)
{
	assert(nullptr != arr);
	assert(0 < size);

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j] < arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}