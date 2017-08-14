/*
Main.c�ļ�
*/


#include <iostream>		//�����using namespace std;��ֹ������Ⱦ
#include <cassert>
#include "insert_sort.h"	//��������
#include "shell_sort.h"		//ϣ������
#include "select_sort.h"	//ѡ������
#include "bubble_sort.h"	//ð������
#include "quick_sort.h"		//��������
#include "heap_sort.h"		//������

#define SORT InsertSort

void Test();
void PrintArr(int* arr, int size);

int main()
{
	Test();

	system("pause");
	return 0;
}


void Test()
{
	int arr[] = {513,10,9,523,8,7,-10,6,30,50,5,4,3,1,2,453945,999,1,1003};
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("����ǰ��");
	PrintArr(arr, size);

	QuickSort(arr, size);

	printf("�����");
	PrintArr(arr, size);
}

void PrintArr(int* arr, int size)
{
	assert(nullptr != arr);
	assert(size > 0);

	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}