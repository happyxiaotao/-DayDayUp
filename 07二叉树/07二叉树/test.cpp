#include "BinaryTree.hpp"

void Test1();

int main()
{

	Test1();

	system("pause");
	return 0;
}

void Test1()
{
	char* str1 = "123####";
	//	char* str2 = "1##";
	char* str2 = "3##";
	BinaryTree<char>  t1(str1, strlen(str1), '#');
	BinaryTree<char>  t2(str2, strlen(str2), '#');

	if (t1.IsSubTree(t2.GetRoot()))
		cout << "t2是t1的子树" << endl;
	else
		cout << "t2不是t1的子树" << endl;
}