/*
1.【基础题】--1.使用两个栈实现一个队列+使用两个队列实现一个栈

ps:两个题几乎是一样的思路，所以放一起了
*/

#include <iostream>
#include <cassert>
#include <stack>
#include <queue> 

template <typename T>
class MyQueue
{
public:
	MyQueue() 
	{}

	void Push(const T& data)
	{
		_s_1.push(data);
	}

	void Pop()
	{
		//如果:_s_2不为空。直接将_s_2中数据pop。
		//如果:_2_2为空，则将_2_1中数据搬运到_s_2中
		
		if (_s_2.empty())
		{
			while (!_s_1.empty())
			{
				T data = _s_1.top();
				_s_1.pop();
				_s_2.push(data);
			}
		}

		if (_s_2.empty())  //pop时，队列不能为空
			assert(0);

		std::cout << _s_2.top() << " ";//打印pop的节点
		_s_2.pop();
	}
private:
	std::stack<T> _s_1;
	std::stack<T> _s_2;	
};


template <typename T>
class MyStack
{
public:
	MyStack()
	{}

	void Push(const T& data) 
	{
		_q_1.push(data);
	}

	void Pop() 
	{
		//将队列_q_1中的元素只保留最后一个，其余全部搬移到_q_2中。
		//然后将，_q_1中保留的元素，出队列。在将_q_2中元素搬移回_q_1中。
		//在整个过程中，_q_2只起中转作用
		if (_q_1.empty())
			assert(0);
		
		while (_q_1.size() > 1)
		{
			T pTemp = _q_1.front();
			_q_2.push(pTemp);
			_q_1.pop();
		}

		std::cout << _q_1.front() << " "; //打印pop的节点
		_q_1.pop();

		while (!_q_2.empty())
		{
			T pTemp = _q_2.front();
			_q_2.pop();
			_q_1.push(pTemp);
		}
	}

private:
	std::queue<T> _q_1;
	std::queue<T> _q_2;
};

int main()
{
	std::cout << "用两个栈实现队列：0-9输出如下：" << std::endl;
	MyQueue<int> q;
	for (int i = 0; i < 10; ++i)
	{
		q.Push(i);
	}
	for (int i = 0; i < 10; ++i)
	{
		q.Pop();
	}

	std::cout << std::endl;

	std::cout << "用两个队列实现栈：0-9输出如下：" << std::endl;
	MyStack<int> s;
	for (int i = 0; i < 10; ++i)
	{
		s.Push(i);
	}
	for (int i = 0; i < 10; ++i)
	{
		s.Pop();
	}

	system("pause");
	return 0;
}




