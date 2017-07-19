/*
1.�������⡿--1.ʹ������ջʵ��һ������+ʹ����������ʵ��һ��ջ

ps:�����⼸����һ����˼·�����Է�һ����
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
		//���:_s_2��Ϊ�ա�ֱ�ӽ�_s_2������pop��
		//���:_2_2Ϊ�գ���_2_1�����ݰ��˵�_s_2��
		
		if (_s_2.empty())
		{
			while (!_s_1.empty())
			{
				T data = _s_1.top();
				_s_1.pop();
				_s_2.push(data);
			}
		}

		if (_s_2.empty())  //popʱ�����в���Ϊ��
			assert(0);

		std::cout << _s_2.top() << " ";//��ӡpop�Ľڵ�
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
		//������_q_1�е�Ԫ��ֻ�������һ��������ȫ�����Ƶ�_q_2�С�
		//Ȼ�󽫣�_q_1�б�����Ԫ�أ������С��ڽ�_q_2��Ԫ�ذ��ƻ�_q_1�С�
		//�����������У�_q_2ֻ����ת����
		if (_q_1.empty())
			assert(0);
		
		while (_q_1.size() > 1)
		{
			T pTemp = _q_1.front();
			_q_2.push(pTemp);
			_q_1.pop();
		}

		std::cout << _q_1.front() << " "; //��ӡpop�Ľڵ�
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
	std::cout << "������ջʵ�ֶ��У�0-9������£�" << std::endl;
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

	std::cout << "����������ʵ��ջ��0-9������£�" << std::endl;
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




