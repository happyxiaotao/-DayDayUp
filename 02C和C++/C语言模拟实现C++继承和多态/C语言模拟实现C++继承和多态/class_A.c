
#include "class_A.h"


//A�Ĺ��캯��
void A_Constructor(A* this, int a)
{
	printf(" A constructor  function\n");
	this->a = a;
}

//A����������
void A_Destructor(A* this)
{
	printf(" A destructor  function\n");
}

// A�ĳ�Ա����
void A_Member(A* this)
{
	printf(" A Member function\n");
	this->a = 1111111;
}