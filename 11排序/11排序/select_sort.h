#pragma once
#include <cassert>
/*
选择排序

最好情况：O（2^N）
最差情况：O（2^N）
平均时间复杂度：O（2^N）
空间复杂度：O（1）
*/

////有巨大的缺陷？
//void SelectSort(int* arr, int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		int maxPos = 0;
//
//		for (int j = 1; j < size - i; j++)
//		{
//			if (arr[maxPos] < arr[j])
//				maxPos = j;
//		}
//
//		if (maxPos != size - i - 1)
//		{
//			int tmp = arr[maxPos];
//			arr[maxPos] = arr[size - i - 1];
//			arr[size - i - 1] = tmp;
//		}
//	}
//}

void SelectSort(int* arr, int size)
{
	assert(nullptr != arr);
	assert(0 < size);
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
