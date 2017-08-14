#pragma once
#include <cassert>
/*
ϣ��������С��������

˼�룺�����˲�������˼��
	1�������ĳ�����������ݿ�����һ�������С�
	2�������������ò�������ķ�����������
	3��������С����������1,2��ѭ����ֱ������Ϊ1������

ʱ�临�Ӷȣ�O��n^1.3���ң�
�ռ临�Ӷȣ�O��1��
�ȶ��ԣ����ȶ�

gap������
gap = gap/2;
gap = gap/3+1; �ǳ���
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