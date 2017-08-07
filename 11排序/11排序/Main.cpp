
#include <iostream>
#include <cassert>
#include "insert_sort.h"
#include "shell_sort.h"

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
	int arr[] = {1, 73,4,59,6,77,4,2,4,452,24,254,2,43,6,5243};
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("ÅÅÐòÇ°£º");
	PrintArr(arr, size);

	ShellSort(arr, size);
	printf("ÅÅÐòºó£º");
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