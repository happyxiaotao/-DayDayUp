#pragma once

#include "class_A.h"

//B�̳�A
typedef struct B
{
	A* base;
	int b;
} B;


//B�Ĺ��캯��
void B_Constructor(B* this, int a, int b);

//B����������
void B_Destructor(B* this);

//B �ĳ�Ա����
void B_Member(B* this);