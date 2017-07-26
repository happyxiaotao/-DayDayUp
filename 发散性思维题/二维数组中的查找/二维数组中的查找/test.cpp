#include <iostream>
#include <cassert>
using namespace std;

int* Find(int arr[], int m, int n, int k)
{
	assert(nullptr != arr);
	assert(0 != m);
	assert(0 != n);

	//初始从右上角开始比较（因为循环一次可以最大化的缩小查找范围）
	int i = 0;	//比较数字所在行
	int j = n-1;  //比较数字所在列
	int *result = nullptr;

	while (i <m && j >= 0)
	{
		if (arr[i*n + j] > k)  //往改行左边寻找
			--j;
		else if (arr[i*n + j] < k) //往该列下面寻找
			++i;
		else //arr[i][j] == k
		{
			result = &arr[i*n + j];
			break;
		}
	}

	return result; //若没有找到，则result依旧为nullptr。
}

int main()
{
	int arr[] = { 1,3,5,6,7,
				  2,6,7,10,43,
				  4,7,8,11,47 ,
				  7,57,454,1000,4300 ,
				  20,600,700,2000,90000,
				};
	
	for (int i = 0; i < 200; ++i)
	{
		if (nullptr != Find(arr, 5, 5, i))
			printf("find %d success!\n", i);
		else
			printf("find %d fail !\n", i);
	}

	system("pause");
	return 0;
}