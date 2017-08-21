#pragma once

#ifndef _CLASS_A_H_
#define _CLASS_A_H_
#include <stdio.h>

#define this THIS //ȥ��this��Ӱ��

typedef struct A
{
	void** vfptr; //���ָ�룬��һ������ָ��
	int m_a;
} A;

void* vftable_A[3]; //�������Ϊָ�����飬A������������麯��

// A�Ĺ��캯��
void Constructor_A(A* this, int a);

// A����������
void Destructor_A(A* this);

// A�ĳ�Ա����
typedef void (*Member_A_VOID)(A*);
typedef void (*Member_A_INT)(A*, int);
typedef void (*Member_A_DOUBLE)(A*, double);

Member_A_VOID A_fun_a;  //A::funa();
Member_A_INT A_fun_b;  //A::funb(int n);
Member_A_DOUBLE A_fun_c; //A::func(double n);

void Fun_Member_A_VOID(A*);
void Fun_Member_A_INT(A*, int);
void Fun_Member_A_DOUBLE(A*, double);


// A���麯��
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