/*
��Ŀ������
����һ������������λ��1�ĸ�����Ҫ��Ч�ʾ����ܵĸߡ�������ȷ�������͸����Ķ�������1�ĸ�����


˼·��
�����ַ�����
1���������ò����ʾһ���ֽ���1�ĸ�����Ȼ����Եõ������ֽ���1�ĸ�����
2�����ö�����&�����ʡ�n&(n-1)����ȥ��������������ߵ�һ��1��
*/

#include <iostream>
using namespace std;

//���õڶ��ַ�����
size_t Get_Number_Of_1(int n)
{
	size_t count = 0;

	while (n)
	{
		n &= n - 1;
		++count;
	}
	return count;
}

int main()
{
	for (int i = -20; i < 20; ++i)
		cout <<i<<"��ʾ�Ķ�����������1�ĸ����ǣ�"<< Get_Number_Of_1(i) << endl;

	system("pause");
	return 0;
}

