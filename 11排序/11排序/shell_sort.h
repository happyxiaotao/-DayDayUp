#pragma once

/*
希尔排序：缩小增量排序
不稳定

利用了插入排序思想

gap：素数
gap = gap/2;
gap = gap/3+1; 非常好
*/

void ShellSort(int* arr, int size)
{
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