#pragma once

#include <cassert>


/*
快速排序思想：
通过一趟排序将要排序的数据分割成独立的两部分，
其中一部分的所有数据都比另外一部分的所有数据都要小。
然后再按此类方法对着两部分数据进行分别进行排序。
最终整个数据达到有序状态。

时间复杂度：O（NlogN）
空间复杂度：O（1）
稳定性：不稳定

冒泡+二分+递归分治
*/

void _quickSort(int* arr, int left, int right)
{
	assert(nullptr != arr);

	if (left > right)
		return;

	int start = left;
	int finish = right;

	int key = arr[start];

	while (start < finish)
	{
		while (start < finish && arr[finish] >= key)
			finish--;
		arr[start] = arr[finish];  //将第一个小的移到低端

		while (start < finish && arr[start] <= key)
			start++;
		arr[finish] = arr[start]; //将第一个大的移到高端

		arr[start] = key; //改变中间节点的值
	}

	_quickSort(arr, left, start-1);   //在左边进行
	_quickSort(arr, finish+1, right);	//在右边进行
}

void QuickSort(int* arr, int size)
{
	assert(nullptr != arr);
	assert(0 < size);

	return _quickSort(arr, 0, size - 1);
}
