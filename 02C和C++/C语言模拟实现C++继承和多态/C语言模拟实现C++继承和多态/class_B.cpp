
#include "class_B.h"


//B的构造函数
void B_Constructor(B* this, int a, int b)
{
	A_Constructor(this->base, a);
	this->b = b;
}

//B的析构函数
void B_Destructor(B* this)
{
	A_Destructor(this->base);
}