#pragma once

#define this THIS //ȥ��this��Ӱ��

typedef struct A
{
	int a;
} A;


// A�Ĺ��캯��
void A_Constructor(A* this, int a);

// A����������
void A_Destructor(A* this);

// A�ĳ�Ա����
void A_Member(A* this);