/*
有如下题目：
已知有n个人和m对好友关系（存于数组r）。
如果两个人是直接或间接的好友（好友的好友的好友…），
则认为他们属于同一个朋友圈，请写程序求出这n个人里一共有多少个朋友圈。
假如：n = 5 ， m = 3 ， r = {{1 , 2} , {2 , 3} , {4 , 5}}，
表示有5个人，1和2是好友，2和3是好友，4和5是好友，
则1、2、3属于一个朋友圈，4、5属于另一个朋友圈，结果为2个朋友圈。
最后请分析所写代码的时间、空间复杂度。
此题最简单并且最高效的解法就是使用并查集
*/




#include "disjsets.h"

void Test()
{

	DisjSets d(10);
	d.unionSets(0, 1);
	d.unionSets(2, 1);
	d.unionSets(5, 6);
	d.unionSets(8, 9);
	d.unionSets(1, 5);

	for (int i = 0; i < 10; i++)
		cout << d.getNumber(i) << endl;
}


int main()
{
	Test(); 

	system("pause");
	return 0;
}