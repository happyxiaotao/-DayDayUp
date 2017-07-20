
/*
题目描述：
元素出栈、入栈顺序的合法性。如：入栈的序列（1,2,3,4,5），出栈序列为（4,5,3,2,1），则合法。
入栈的序列（1,2,3,4,5），出栈序列为（4,5,2,3,1），则不合法。

思路：
可以利用一个辅助的栈空间。
1，把第一个序列v1中的数字逐个压入栈中，压入的过程中把第二个序列v2中元素与栈首元素比较。
2，如果相同，则出栈，同时,v2下标往后移，准备进行下一次比较。
3，如果不同，则将v1中数据依次入栈，直到满足1中的条件或者没有数据为止。
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
bool Check_Out_Stack_Order(const vector<T>& v_1, const vector<T> v_2)
{
	//两个序列个数不相同
	if (v_1.size() != v_2.size()) 
		return false;

	//此时v_1,v_2中元素个数肯定相同
	stack<T> s;			 //辅助栈，造成v_2序列的栈，这里称为原栈
	size_t index_1 = 0;  //作为v_1的下标
	size_t index_2 = 0;  //作为v_2的下标
	while (index_2 < v_2.size())    //包含了v_1,v_2都为空的情况
	{
		//当s为空,或辅助栈顶元素不等于v_2[index_2]时，v_1中元素要不停的入辅助栈，直到没有元素可用
		while (s.empty() || s.top() != v_2[index_2])
		{
			if (index_1 < v_1.size())
				s.push(v_1[index_1++]);
			else
				return false;  //将v_1中数据全部入栈，还是没有在v_2中发现有相等的，说明，两个序列含有的数据不一样
		}
		//此时，s.top()=v_2[index_2]，说明原栈此处有出栈操作，得到v_2中的v_2[index]。
		s.pop();
		++index_2;
	}
	if (s.empty())
		return true;
	else
		return false;
}	

int main()
{	
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 4,5,3,2,1 };
	vector<int> v3 = { 4,5,2,3,1 };

	cout << "v1 与 v2是否满足出栈、入栈的合法性？";
	if (Check_Out_Stack_Order(v1, v2))
		cout << " 满足" << endl;
	else
		cout << "不满足" << endl;

	cout << "v1 与 v3是否满足出栈、入栈的合法性？";
	if (Check_Out_Stack_Order(v1, v3))
		cout << " 满足" << endl;
	else
		cout << "不满足" << endl;

	system("pause");
	return 0;
}