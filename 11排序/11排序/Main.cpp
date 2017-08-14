/*
Main.cÎÄ¼ş
*/


#include <iostream>		//²»Ìí¼Óusing namespace std;·ÀÖ¹ÃüÃûÎÛÈ¾
#include <time.h>
#include <cassert>
#include "insert_sort.h"	//²åÈëÅÅĞò
#include "shell_sort.h"		//Ï£¶ûÅÅĞò
#include "select_sort.h"	//Ñ¡ÔñÅÅĞò
#include "bubble_sort.h"	//Ã°ÅİÅÅĞò
#include "quick_sort.h"		//¿ìËÙÅÅĞò
#include "heap_sort.h"		//¶ÑÅÅĞò
#include "merge_sort.h"     //¹é²¢ÅÅĞò
#include "count_sort.h"		//¼ÆÊıÅÅĞò

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

	printf("ÅÅĞòÇ°£º");
	PrintArr(arr, size);

	QuickSort(arr, size);

	printf("ÅÅĞòºó£º");
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