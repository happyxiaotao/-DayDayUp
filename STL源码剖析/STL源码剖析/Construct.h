#pragma once

#ifndef _CONSTRUCT_H_
#define _CONSTRUCT_H_

#include <new> //��Ҫʹ��placement new
#include "Trivial.h"

//ȫ�ֹ��캯��
template <typename T, typename ValueType>
inline void Construct(T* p, const ValyeType& value) //Ϊʲô��һ����������const��
{
	new (p) T(value);
}

//ȫ����������
//ͨ�������Ĳ�ͬ����Ϊ����

//��һ�֣�ֻ����һ������
template <typename T>
inline void Dsetroy(T* p)
{
	p->~T();
}

//�ڶ��֣������������������������һ���Ҫͨ�� ������ȡ ��������Ӧ������

//ģ�庯������
template <typename ForwardIterator>
inline void _Destroy(ForwardIterator first, ForwardIterator last, FalseType)
{
	for (; first < last; ++first)
		Destroy(first);
}

template <typename ForwardIterator>
inline void _Destroy(ForwardIterator first, ForwardIterator last, TrueType)
{}

template <typename ForwardIterator>
inline void Destroy(ForwardIterator first, ForwardIterator last)
{
	_Destroy(first, last);
}



#endif // _CONSTRUCT_H_
