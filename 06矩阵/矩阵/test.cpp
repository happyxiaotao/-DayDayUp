#include "SymmetricMatrix.hpp"

int main()
{
	Martix<int> martix((int *)MartixArry, MAX_ROW);

	cout << martix << endl;//打印对称矩阵

	martix.Access(3, 3) = 10;//对矩阵进行修改

	cout << martix << endl;//打印对称矩阵

	system("pause");
	return 0;
}