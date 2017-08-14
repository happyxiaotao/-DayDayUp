#pragma once
#include <cassert>
/*
希尔排序：缩小增量排序

思想：利用了插入排序思想
	1，将相隔某个增量的数据看做是一个子序列。
	2，将子序列利用插入排序的方法进行排序。
	3，依次缩小增量，进行1,2步循环，直到增量为1结束。

时间复杂度：O（n^1.3左右）
空间复杂度：O（1）
稳定性：不稳定

gap：素数
gap = gap/2;
gap = gap/3+1; 非常好
*/

void ShellSort(int* arr, int size)
{
	assert(nullptr != arr);
	assert(0 < size);
	int gap = size;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int idx = gap; idx < size; idx+=gap)
		{
			int key = arr[idx];
			int end = idx - gap;

			while (end > 0 && arr[end] > key)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}

			arr[end] = key;
		}
	}
}