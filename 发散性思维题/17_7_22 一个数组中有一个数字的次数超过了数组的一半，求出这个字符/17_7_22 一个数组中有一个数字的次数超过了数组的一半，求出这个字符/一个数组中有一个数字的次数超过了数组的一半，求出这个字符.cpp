/*
��Ŀ������
һ����������һ�����ֵĴ��������������һ�룬�������ַ����磺int a[]={2,3,2,2,2,2,2,5,4,1,2,3}���������һ���������2��
*/


/*
˼·��
�����ĳ���ַ����ִ������������ܸ�����һ�롣
��ô�����ַ��������ַ���һ����һ�������������ַ���Ȼ����ʣ�ࡣ
���ԣ����ǿ��Զ���һ��ch�洢һ���ַ���flag��ʾ����������ch�ַ���֪���ִ�������֮��ʣ�µĴ�����
1,��ͷ��ʼ�����������������е��ַ���ch�Ƚϡ�
2,�����ͬ����flag++������flag--;
3,��flagΪ0ʱ����ʾ��ch�����������������ĿҪ����������������һ���ַ��滻��
4�����գ�������֮��ch����ľ���������ĿҪ����ַ���
*/


#include <iostream>
#include <cassert>
using namespace std;

char Check_More_Than_Halt(const char *arr, size_t size)
{
	assert(arr);
	assert(size);

	int ch = arr[0];
	int flag = 1;
	int i = 1;

	for (; i < size; ++i)
	{
		if (0 == flag)  //flagΪ0ʱ����Ҫ����ch
		{
			ch = arr[i];
			flag = 1;
		}
		else 
		{
			if (ch == arr[i]) //�����ȣ���flag++;����flag--��
				++flag;
			else
				--flag;
		}
	}
	//��ʱ��ch�ض��洢���ִ��������������һ����ַ�
	return ch;;
}

void Test()
{
	char *arr1 = "123453333333";
	char *arr2 = "5441448494247448444";

	cout << Check_More_Than_Halt(arr2, sizeof(arr2)/sizeof(arr2[0])) << endl;
}

int main()
{
	Test();

	system("pause");
	return 0;
}

