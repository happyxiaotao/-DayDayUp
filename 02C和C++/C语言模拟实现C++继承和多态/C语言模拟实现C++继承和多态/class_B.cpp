
#include "class_B.h"


//B�Ĺ��캯��
void B_Constructor(B* this, int a, int b)
{
	A_Constructor(this->base, a);
	this->b = b;
}

//B����������
void B_Destructor(B* this)
{
	A_Destructor(this->base);
}