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



#include "unionset.h"

void Test()
{
	UnionSet u(5);

	u.UnionFriends(1, 2);
	u.UnionFriends(4, 5);
	u.UnionFriends(2, 3);

	cout << u.GetCountFriends(1) << endl;
	cout << u.GetCountFriends(2) << endl;
	cout << u.GetCountFriends(3) << endl;
	cout << u.GetCountFriends(4) << endl;
	cout << u.GetCountFriends(5) << endl;

	cout << "打印根：" << endl;
	cout << u.GetRoot(1) << endl;
	cout << u.GetRoot(2) << endl;
	cout << u.GetRoot(3) << endl;
	cout << u.GetRoot(4) << endl;
	cout << u.GetRoot(5) << endl;
}


int main()
{
	Test();

	system("pause");
	return 0;
}