#pragma once
#ifndef _CIRULARQUEUE_H_
#define _CIRULARQUEUE_H_

#include <iostream>
using namespace std;

//循环队列，队列大小固定，将空余一个单元出来，使得容易判断循环列表的空或满的状态
//队列为空时:m_front = m_rear;队列满时：(m_rear+1)%m_capacity = m_front.
//返回循环队列中元素个数：(m_rear+m_capacity-m_front)%m_capacity;
template <typename T>
class CirQueue
{
public:
	CirQueue();
	~CirQueue();

	void Push(const T& data);//入队列
	void Pop();//出队列
	bool Empty()//判断循环队列是否为空
		size_t Size();//返回循环队列元素个数
	T& Front();//返回循环头元素
	T& Back();//返回循环队列尾元素
private:
	bool CheckCapacity();//判断循环队列是否已满
private:
	T* m_pData;//指向一块连续空间
	size_t m_front;//队列头编号(从0开始)(其对应的单元永远表示空出来的那一个)
	size_t m_rear;//队列尾编号(从0开始)
	size_t m_capacity;//循环队列最大容量

};

template <typename T>
CirQueue<T>::CirQueue()
	: m_pData(new T[10])
	, m_front(0)
	, m_rear(0)
	, m_capacity(10)
{
	memset(m_pData, 0, m_capacity*sizeof(T));//队列空间赋为空
}

template <typename T>
CirQueue<T>::~CirQueue()
{
	if (m_pData)
	{
		delete[] m_pData;
		m_pData = nullptr;//好习惯
		m_front = 0;
		m_rear = 0;
		m_capacity = 0;
	}
}

//判断循环队列是否已满
template <typename T>
bool CirQueue<T>::CheckCapacity()
{
	return (m_rear + 1) % m_capacity != m_front;
}
//判断循环队列是否为空
template <typename T>
bool CirQueue<T>::Empty()
{
	return m_rear == m_front;
}
//元素入队列
template <typename T>
void CirQueue<T>::Push(const T& data)
{
	if (CheckCapacity())
	{
		m_pData[++m_rear] = data;
		m_rear %= m_capacity;//因为是循环队列，所以可以循环
	}
	else
		cerr << "CirQueue is full !" << endl;
}

template <typename T>
void CirQueue<T>::Pop()
{
	if (!Empty())
		m_front = (m_front + 1) % m_capacity;
	else
		cerr << "CirQueue is empyt !" << endl;
}

template <typename T>
size_t CirQueue<T>::Size()
{
	return (m_rear + m_capacity - m_front) % m_capacity;//m_rear,m_capacity,m_front都是size_t,所以先加后减。
}

template <typename T>
T& CirQueue<T>::Front()
{
	if (!Empty())
	{
		size_t head = (m_front + 1) % m_capacity;//m_front指向的永远都是空出来的那一个单元对应的下标
		return m_pData[head];
	}
	cerr << "CirQueue is empty !" << endl;
	exit(1);
}

template <typename T>
T& CirQueue<T>::Back()
{
	if (!Empty())
		return m_pData[m_rear];
	cerr << "CirQueue is empty !" << endl;
	exit(2);
}

#endif //_CIRULARQUEUE_H_