#pragma once

//选择排序


//有巨大的缺陷
void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int maxPos = 0;

		for (int j = 1; j < size - i; j++)
		{
			if (arr[maxPos] < arr[j])
				maxPos = j;
		}

		if (maxPos != size - i - 1)
		{
			int tmp = arr[maxPos];
			arr[maxPos] = arr[size - i - 1];
			arr[size - i - 1] = tmp;
		}
	}
}

void SelectSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int 
	}
}