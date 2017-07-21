/*
��Ŀ���� 
����һ������N����ôN�Ľ׳�N��ĩβ�ж��ٸ�0�أ����磺N��10��N����3 628 800��N����ĩβ������0��
*/


/*
˼·��
���Ǳ��֮���ϵ�һ����Ŀ��
���������ֽ��������
1��
2��
*/
#include <iostream>
using namespace std;

//�ⷨ1:����1~N�У�ÿ��������ʽ�ֽ���5�ĸ�����
size_t Get_Number_Of_Zeroes_InTail_1(size_t n)
{
	int count = 0;
	for (size_t i = 1; i <= n; ++i)
	{
		size_t j = i;
		while (0 == j % 5)
		{
			++count;
			j /= 5;
		}
	}
	return count;
}

//�ⷨ2��
size_t Get_Number_Of_Zeroes_InTail_2(size_t n)
{
	int count = 0;

	while (n)
	{
		count += n / 5;
		n /= 5;
	}

	return count;
}

int main()
{

	for (int i = 0; i < 11; ++i)
	{
		cout << i << "�Ľ׳�ĩβ0�ĸ�����"<<Get_Number_Of_Zeroes_InTail_2(i) << endl;
	}
	system("pause");
	return 0;
}