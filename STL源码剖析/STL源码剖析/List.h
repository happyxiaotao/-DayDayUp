#pragma once

#ifndef _LIST_H_
#define _LIST_H_

template <typename T>
struct Node
{
	Node(const T& data = T())
		: _data(data)
		, _pPre(nullptr)
		, _pNext(nullptr)
	{}

	T	  _data;
	Node* _pPre;
	Node* _pNext;
}; 

template <typename T, typename Ref, typename Ptr>
class ListIterator
{
public:
	typedef ListIterator<T, Ref, Ptr> Self;
	typedef T ValueType;
	typedef Ref Reference;
	typedef Ptr Pointer;
public:
	ListIterator() 
		: _pNode(nullptr)
	{}

	ListIterator(Node* p)
		: _pNode(p)
	{}

private:
	Node* _pNode;
};

#endif //_LIST_H_
