/*
1.【基础题】--1.使用两个栈实现一个队列+使用两个队列实现一个栈

ps:两个题几乎是一样的思路，所以放一起了
*/

#include <iostream>
#include <stack>
#include <queue> 

template <typename T>
class MyStack
{

private:
	std::stack<T> _s_1;
	std::stack<T> _s_2;
};

template <typename T>
class MyQueue
{
private:
	std::queue<T> _q_1;
	std::queue<T> _q_1;
};

int main()
{
	
	system("pause");
	return 0;
}



