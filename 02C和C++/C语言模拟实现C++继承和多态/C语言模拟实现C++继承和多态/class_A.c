
#include "class_A.h"


//A的构造函数
void A_Constructor(A* this, int a)
{
	printf(" A constructor  function\n");
	this->a = a;
}

//A的析构函数
void A_Destructor(A* this)
{
	printf(" A destructor  function\n");
}

// A的成员函数
void A_Member(A* this)
{
	printf(" A Member function\n");
	this->a = 1111111;
}