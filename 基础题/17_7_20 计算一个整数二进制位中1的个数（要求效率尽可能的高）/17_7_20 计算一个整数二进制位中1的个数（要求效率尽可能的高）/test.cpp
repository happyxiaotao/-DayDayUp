/*
题目描述：
计算一个整数二进制位中1的个数。要求效率尽可能的高。且能正确求正数和负数的二进制中1的个数。


思路：
有两种方法：
1，可以利用查表法表示一个字节中1的个数。然后可以得到任意字节中1的个数。
2，利用二进制&的性质。n&(n-1)可以去掉二进制中最左边的一个1。
*/

#include <iostream>
using namespace std;

//利用第二种方法：
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
		cout <<i<<"表示的二进制序列中1的个数是："<< Get_Number_Of_1(i) << endl;

	system("pause");
	return 0;
}

