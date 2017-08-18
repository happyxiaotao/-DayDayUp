#pragma once

#define this THIS //去掉this的影响

typedef struct A
{
	int a;
} A;


// A的构造函数
void A_Constructor(A* this, int a);

// A的析构函数
void A_Destructor(A* this);

// A的成员函数
void A_Member(A* this);