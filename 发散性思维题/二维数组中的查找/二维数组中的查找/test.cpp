#include <iostream>
#include <cassert>
using namespace std;

int* Find(int arr[], int m, int n, int k)
{
	assert(nullptr != arr);
	assert(0 != m);
	assert(0 != n);

	//��ʼ�����Ͻǿ�ʼ�Ƚϣ���Ϊѭ��һ�ο�����󻯵���С���ҷ�Χ��
	int i = 0;	//�Ƚ�����������
	int j = n-1;  //�Ƚ�����������
	int *result = nullptr;

	while (i <m && j >= 0)
	{
		if (arr[i*n + j] > k)  //���������Ѱ��
			--j;
		else if (arr[i*n + j] < k) //����������Ѱ��
			++i;
		else //arr[i][j] == k
		{
			result = &arr[i*n + j];
			break;
		}
	}

	return result; //��û���ҵ�����result����Ϊnullptr��
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