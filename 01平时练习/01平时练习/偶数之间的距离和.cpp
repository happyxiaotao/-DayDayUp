//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//using namespace std;
//
//int* getdata(int n)
//{
//	int i = 0;
//	int* data = NULL;
//
//	if (0 == n)
//		return NULL;
//	data = (int*)malloc(sizeof(int)*n);
//
//	for (; i < n; i++)
//		scanf("%d", &data[i]);
//	return data;
//}
//
//void setNum(int* data, int begin, int end, int* num, int index)
//{
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	assert(data != NULL);
//	assert(num != NULL);
//	assert(begin < end);
//
//	for (i = begin + 1; i <= end - 1; i += 2)
//	{
//		for (j = 2; j <= (i >> 1); j++)
//		{
//			if (0 == i%j)
//				break;
//		}
//		if (j > (i >> 1))
//			count++;
//	}
//	num[index] = count;
//}
//
//int getsum(int* data, int length)
//{
//	int* num = NULL;
//	int i = 0;
//	int sum = 0;
//	assert(NULL != data);
//	assert(length > 0);
//
//	num = (int*)malloc(sizeof(int)*length);
//	for (i = 1; i < length; i++)
//		setNum(data, data[i - 1], data[i], num, i - 1);
//
//	for (i = 0; i < length - 1; i++)
//		sum += num[i];
//	sum *= (length-1);
//
//	free(num);  
//	return sum;
//}
///*
//int main()
//{
//	int n = 0;
//	int* data = NULL;
//	int sum = 0;
//	int i = 0;
//	scanf("%d", &n); // get n
//
//	data = getdata(n); // get data array
//
//	if (data)
//		sum = getsum(data, n);//get sum
//	else	//data=NULL
//		return 1;
//
//	printf("sum = %d\n", sum);
//
//	free(data);
//
//	system("pause");
//	return 0;
//}
//*/