#pragma once
#include <assert.h>


/*
插入排序
最优场景：数据有序-->O（N）
最差场景：数据倒序-->O（N^2）
稳定

适应的场景：数据量小，数据接近有序。

Q：给你大而杂乱的数据，让你用插入排序的思想做？
A：每隔某个数，将数据看做是一个分组比如gap=3，将该组数据进行插入排序。此时，数据以及接近有序了。
在将数据之间的间隔减少1个，在进行分组，并且进行插入排序。这样数据会越来越有序。插入排序的效率更高。
*/

//原版
//时间复杂度O(n^2)，空间复杂度O（1）
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

//优化：减少循环内的比较次数
//利用二分查找直接找到到插入位置
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

		//比较次数 O（log2N）
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (array[mid] > key)
				right = mid - 1;
			else
				left = mid + 1;
		}

		//left保存存储位置
		while (end >= left)
		{
			array[end + 1] = array[end];
			end--;
		}

		array[end + 1] = key;
	}
}