#pragma once
#include <cassert>

/*
�鲢����

˼�룺ʹ���˵ݹ����˼��

	1,���������п�������������ɣ������������֡�
	2���ص�֮�󣬺ϲ��������򲿷֡�

��������O��NlogN��
��������O��NlogN��
ƽ��ʱ�临�Ӷȣ�O��NlogN��

�ռ临�Ӷȣ�O��N��
�ȶ��ԣ��ȶ�
*/

void merge(int* arr, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	
	int* temp = new int[right - left + 1];  //������ʱ����ռ�
	int count = 0; //��¼temp���齫Ҫʹ�õ�λ��

	while (i <= mid && j <= right)//���������򲿷ֺϲ����洢��temp��
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

	while (count >= 0)  //����ʱ�������������ݣ�����arr������
		arr[left + count] = temp[count];

}

void _mergeSort(int* arr, int left, int right)
{
	assert(nullptr != arr);
	assert(left <= right);

	if (left == right)  //ֻ��һ��Ԫ�أ�Ĭ������
		return;

	//����������������Ԫ�أ����з���
	int mid = left + ((right - left) >> 1);
	
	_mergeSort(arr, left, mid);  //���������
	_mergeSort(arr, mid+1, right);	//���ұ�����

	merge(arr, left, mid, right);  //���кϲ�����
}

void MergeSort(int* arr, int size)
{
	assert(nullptr != arr);
	assert(0 < size);

	_mergeSort(arr, 0, size - 1);
}