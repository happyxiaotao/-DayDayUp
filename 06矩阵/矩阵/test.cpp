#include "SymmetricMatrix.hpp"

int main()
{
	Martix<int> martix((int *)MartixArry, MAX_ROW);

	cout << martix << endl;//��ӡ�Գƾ���

	martix.Access(3, 3) = 10;//�Ծ�������޸�

	cout << martix << endl;//��ӡ�Գƾ���

	system("pause");
	return 0;
}