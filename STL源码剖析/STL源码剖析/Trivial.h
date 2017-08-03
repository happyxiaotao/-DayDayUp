//#pragma once 与下面功能重复
/*
萃取
1，迭代器的类型。
2，类的类型
*/

#ifndef _TRIVIAL_H_
#define _TRIVIAL_H_


struct TrueType
{};
struct FalseType
{};

template <class T>
struct Type_Traits
{
	typedef FalseType Has_Trivial_Default_Construtor;
	typedef FalseType Has_Trivial_Copy_Constructor;
	typedef FalseType Has_Trivial_Assignment_Operator;
	typedef FalseType Has_Trivial_Destrutor;
	typedef FalseType Is_POD_Type;
};

template <>
struct Type_Traits<char>
{
	typedef TrueType Has_Trivial_Default_Construtor;
	typedef TrueType Has_Trivial_Copy_Constructor;
	typedef TrueType Has_Trivial_Assignment_Operator;
	typedef TrueType Has_Trivial_Destrutor;
	typedef TrueType Is_POD_Type;
};


template <>
struct Type_Traits<int>
{
	typedef TrueType Has_Trivial_Default_Construtor;
	typedef TrueType Has_Trivial_Copy_Constructor;
	typedef TrueType Has_Trivial_Assignment_Operator;
	typedef TrueType Has_Trivial_Destrutor;
	typedef TrueType Is_POD_Type;
};

template <class T>
struct Iterator_Traits
{
	typedef typename T::ValueType ValueType;
};

template <class T>
struct Iterator_Traits<T*>
{
	typedef T ValueType;
};


void Prin(FalseType t)
{
	cout << "FalseType" << endl;
}

void Prin(TrueType t)
{
	cout << "TrueType" << endl;
}

void Test()
{
	Prin(Type_Traits<int>::Is_POD_Type());
	Prin(Type_Traits<FalseType>::Is_POD_Type());
}

#endif //_TRIVIAL_H_
