/*
题目描述 
给定一个整数N，那么N的阶乘N！末尾有多少个0呢？例如：N＝10，N！＝3 628 800，N！的末尾有两个0。
*/


/*
思路：
这是编程之美上的一道题目。
推算下来就是计算N!中可以整求的5的多少次方
给出了两种解决方法。
1，
2，
*/
#include <iostream>
using namespace std;

//解法1:计算1~N中，每个数的因式分解中5的个数。
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

//解法2：
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
		cout << i << "的阶乘末尾0的个数："<<Get_Number_Of_Zeroes_InTail_2(i) << endl;
	}
	system("pause");
	return 0;
}
