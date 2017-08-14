#pragma once

#include <cassert>


/*
��������˼�룺
ͨ��һ������Ҫ��������ݷָ�ɶ����������֣�
����һ���ֵ��������ݶ�������һ���ֵ��������ݶ�ҪС��
Ȼ���ٰ����෽���������������ݽ��зֱ��������
�����������ݴﵽ����״̬��

ʱ�临�Ӷȣ�O��NlogN��
�ռ临�Ӷȣ�O��1��
�ȶ��ԣ����ȶ�

ð��+����+�ݹ����
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
		arr[start] = arr[finish];  //����һ��С���Ƶ��Ͷ�

		while (start < finish && arr[start] <= key)
			start++;
		arr[finish] = arr[start]; //����һ������Ƶ��߶�

		arr[start] = key; //�ı��м�ڵ��ֵ
	}

	_quickSort(arr, left, start-1);   //����߽���
	_quickSort(arr, finish+1, right);	//���ұ߽���
}

void QuickSort(int* arr, int size)
{
	assert(nullptr != arr);
	assert(0 < size);

	return _quickSort(arr, 0, size - 1);
}
