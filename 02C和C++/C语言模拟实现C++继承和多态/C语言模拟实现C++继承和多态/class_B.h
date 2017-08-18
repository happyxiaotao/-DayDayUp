#pragma once

#include "class_A.h"

//B继承A
typedef struct B
{
	A* base;
	int b;
} B;


//B的构造函数
void B_Constructor(B* this, int a, int b);

//B的析构函数
void B_Destructor(B* this);

//B 的成员函数
void B_Member(B* this);