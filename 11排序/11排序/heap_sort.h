#pragma once
#include <cassert>
/*
堆排序：
思想：
	1，将序列调整成一个大堆。
	2，交换堆顶与最后一个元素位置，这样最后一个元素就是值最大的。
	3，将size--，循环1,2步，直到size为0。

堆的概念：
	如果有一个关键码的集合K = {k0，k1， k2，…，kn-1}，把它的所有元素按完全二叉树
	的顺序存储方式存储在一个一维数组中，并满足：Ki <= K2*i+1 且 Ki<= K2*i+2
	(Ki >= K2*i+1 且 Ki >= K2*i+2) i = 0，1，2…，则称这个堆为最小堆(或最大堆)

时间复杂度：O（NlogN）
空间复杂度：O（1）
稳定性：不稳定

*/

void swap(int* arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//采用堆中向下调整的思想。时间复杂度O（logN）
void AdjustHeap(int* arr, int size, int parent)
{
	assert(nullptr != arr);
	assert(0 < size);
	assert(0 <= parent);

	int child = parent * 2 + 1;
	while (child < size)
	{
		//如果右子树存在，找出左右子树根节点中最大的
		if (child + 1 < size && arr[child + 1] > arr[child])
			child++;

		if (arr[child] > arr[parent])
		{
			swap(arr, child, parent);
			parent = child; //更新根节点，进入下一级子树中调整
			child = parent * 2 + 1;
		}
		else
			break;  //以parent为根的子树已经排好序
	}
}

void HeapSort(int* arr, int size)
{
	assert(nullptr != arr);
	assert(0 < size);
	for (int i = (size - 2) >> 1; i >= 0; i--)
		AdjustHeap(arr, size, i);  //调整堆

	for (int i = 0; i < size; i++) 
	{
		//将头与尾交换，并且size--
		swap(arr, 0, size);
		size--;
		AdjustHeap(arr, size, i);
	}
}
