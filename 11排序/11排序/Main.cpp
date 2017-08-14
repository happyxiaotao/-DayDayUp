/*
Main.c�ļ�
*/


#include <iostream>		//�����using namespace std;��ֹ������Ⱦ
#include <time.h>
#include <cassert>
#include "insert_sort.h"	//��������
#include "shell_sort.h"		//ϣ������
#include "select_sort.h"	//ѡ������
#include "bubble_sort.h"	//ð������
#include "quick_sort.h"		//��������
#include "heap_sort.h"		//������
#include "merge_sort.h"     //�鲢����
#include "count_sort.h"		//��������

#define SORT CountSort

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
	srand((unsigned)time(0));
	
	const int size = 20;
	int arr[size] = {0};
	for (int i = 0; i < size; i++)
		arr[i] = rand()-rand()+rand();

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