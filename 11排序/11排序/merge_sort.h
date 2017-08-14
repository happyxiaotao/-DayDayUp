#pragma once
#include <cassert>

/*
归并排序：

思想：使用了递归分治思想

	1,将待排序列看成是两部分组成，先排序两部分。
	2，回调之后，合并两个有序部分。

最好情况：O（NlogN）
最差情况：O（NlogN）
平均时间复杂度：O（NlogN）

空间复杂度：O（N）
稳定性：稳定
*/

void merge(int* arr, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	
	int* temp = new int[right - left + 1];  //开辟临时数组空间
	int count = 0; //记录temp数组将要使用的位置

	while (i <= mid && j <= right)//将两个有序部分合并，存储在temp中
	{
		while (arr[i] <= arr[j])
		{
			temp[count] = arr[i];
			count++;
			i++;
		}

		while (arr[i] >= arr[j])
		{
			temp[count] = arr[j];
			count++;
			j++;
		}
	}

	while (count >= 0)  //将临时数组中有序数据，放入arr数组中
		arr[left + count] = temp[count];

}

void _mergeSort(int* arr, int left, int right)
{
	assert(nullptr != arr);
	assert(left <= right);

	if (left == right)  //只有一个元素，默认有序
		return;

	//包含两个及其以上元素，进行分治
	int mid = left + ((right - left) >> 1);
	
	_mergeSort(arr, left, mid);  //对左边排序
	_mergeSort(arr, mid+1, right);	//对右边排序

	merge(arr, left, mid, right);  //进行合并操作
}

void MergeSort(int* arr, int size)
{
	assert(nullptr != arr);
	assert(0 < size);

	_mergeSort(arr, 0, size - 1);
}