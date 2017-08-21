#pragma once

#ifndef _CLASS_B_H_
#define _CLASS_B_H_

#include "class_A.h"

//B继承A
typedef struct B
{
	A m_base;
	int m_b;
} B;


//B的构造函数
void B_Constructor(B* this, int a, int b);

//B的析构函数
void B_Destructor(B* this);

// B的成员函数
typedef void(*Member_B_VOID)(B*);
typedef void(*Member_B_INT)(B*, int);
typedef void(*Member_B_DOUBLE)(B*, double);


Member_B_VOID B_fun_a;  //B::funa();
Member_B_INT B_fun_b;  //B::funb(int n);
Member_B_DOUBLE B_fun_c; //B::func(double n);


void Fun_Member_B_VOID(B*);
void Fun_Member_B_INT(B*, int);
void Fun_Member_B_DOUBLE(B*, double);


// B的虚函数
typedef void(*VirTual_Member_B_INT)(B*, int);
typedef void(*Virtual_Member_B_DOUBLE)(B*, double);


VirTual_Member_B_INT B_fun_d; //virtual B::fund();将A的fund重写
Virtual_Member_B_DOUBLE B_fun_e; //virtual B::fune()，将A的fune重写

void Fun_Virtual_Member_B_INT(B*, int); 
void Fun_Virtual_Member_B_DOUBLE(B*, double);

#endif //_CLASS_B_H_