#pragma once

#ifndef _CONSTRUCT_H_
#define _CONSTRUCT_H_

#include <new> //需要使用placement new
#include "Trivial.h"

//全局构造函数
template <typename T, typename ValueType>
inline void Construct(T* p, const ValyeType& value) //为什么第一个参数不加const？
{
	new (p) T(value);
}

//全局析构函数
//通过参数的不同，分为两种

//第一种，只接受一个参数
template <typename T>
inline void Dsetroy(T* p)
{
	p->~T();
}

//第二种，接受两个迭代器参数，并且还需要通过 类型萃取 来调用相应函数。

//模板函数重载
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
