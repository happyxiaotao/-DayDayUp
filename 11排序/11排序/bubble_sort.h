#pragma once

#include <cassert>
/*
ð������
˼��:ͨ��������Ԫ�صıȽϺͽ���,����С��Ԫ��ð�ݵ�����

	��ѭ��size-1��
	��ѭ��size-1-i;

ʱ�临�Ӷȣ�O��2^N��
�ռ临�Ӷȣ�O��1��
�ȶ��ԣ��ȶ�

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