#pragma once
#include <cassert>
/*
������
˼�룺
	1�������е�����һ����ѡ�
	2�������Ѷ������һ��Ԫ��λ�ã��������һ��Ԫ�ؾ���ֵ���ġ�
	3����size--��ѭ��1,2����ֱ��sizeΪ0��

�ѵĸ��
	�����һ���ؼ���ļ���K = {k0��k1�� k2������kn-1}������������Ԫ�ذ���ȫ������
	��˳��洢��ʽ�洢��һ��һά�����У������㣺Ki <= K2*i+1 �� Ki<= K2*i+2
	(Ki >= K2*i+1 �� Ki >= K2*i+2) i = 0��1��2������������Ϊ��С��(������)

ʱ�临�Ӷȣ�O��NlogN��
�ռ临�Ӷȣ�O��1��
�ȶ��ԣ����ȶ�

*/

void swap(int* arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//���ö������µ�����˼�롣ʱ�临�Ӷ�O��logN��
void AdjustHeap(int* arr, int size, int parent)
{
	assert(nullptr != arr);
	assert(0 < size);
	assert(0 <= parent);

	int child = parent * 2 + 1;
	while (child < size)
	{
		//������������ڣ��ҳ������������ڵ�������
		if (child + 1 < size && arr[child + 1] > arr[child])
			child++;

		if (arr[child] > arr[parent])
		{
			swap(arr, child, parent);
			parent = child; //���¸��ڵ㣬������һ�������е���
			child = parent * 2 + 1;
		}
		else
			break;  //��parentΪ���������Ѿ��ź���
	}
}

void HeapSort(int* arr, int size)
{
	assert(nullptr != arr);
	assert(0 < size);
	for (int i = (size - 2) >> 1; i >= 0; i--)
		AdjustHeap(arr, size, i);  //������

	for (int i = 0; i < size; i++) 
	{
		//��ͷ��β����������size--
		swap(arr, 0, size);
		size--;
		AdjustHeap(arr, size, i);
	}
}
