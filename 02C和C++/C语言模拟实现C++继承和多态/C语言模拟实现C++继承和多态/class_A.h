#pragma once

#ifndef _CLASS_A_H_
#define _CLASS_A_H_
#include <stdio.h>

#define this THIS //去掉this的影响

typedef struct A
{
	void** vfptr; //虚表指针，是一个二级指针
	int m_a;
} A;

void* vftable_A[3]; //虚表类型为指针数组，A的虚表，有三个虚函数

// A的构造函数
void Constructor_A(A* this, int a);

// A的析构函数
void Destructor_A(A* this);

// A的成员函数
typedef void (*Member_A_VOID)(A*);
typedef void (*Member_A_INT)(A*, int);
typedef void (*Member_A_DOUBLE)(A*, double);

Member_A_VOID A_fun_a;  //A::funa();
Member_A_INT A_fun_b;  //A::funb(int n);
Member_A_DOUBLE A_fun_c; //A::func(double n);

void Fun_Member_A_VOID(A*);
void Fun_Member_A_INT(A*, int);
void Fun_Member_A_DOUBLE(A*, double);


// A的虚函数
typedef void (*VirTual_Member_A_INT)(A*, int);
typedef void (*Virtual_Member_A_DOUBLE)(A*, double);
typedef void(*Virtual_Member_A_Float)(A*, float);

VirTual_Member_A_INT A_fun_d; //virtual A::fund();
Virtual_Member_A_DOUBLE A_fun_e; //virtual A::fune();
Virtual_Member_A_Float A_fun_f; //virtual A::funf();

void Fun_Virtual_Member_A_INT(A*, int);
void Fun_Virtual_Member_A_DOUBLE(A*, double);
void Fun_Virtual_Member_A_FLOAT(A*, float);

#endif//_CLASS_A_H_