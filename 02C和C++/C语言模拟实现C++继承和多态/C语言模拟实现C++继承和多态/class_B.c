
#include "class_B.h"


//B的构造函数
void Constructor_B(B* this, int a, int b)
{
	Constructor_A(&(this->m_base), a);

	B_fun_a = Fun_Member_B_VOID;
	B_fun_b = Fun_Member_B_INT;
	B_fun_c = Fun_Member_B_DOUBLE;
	B_fun_d = Fun_Virtual_Member_B_INT;
	B_fun_e = Fun_Virtual_Member_B_DOUBLE;

	this->m_base.vfptr[0] = B_fun_c;  //对A的虚表进行改写
	this->m_base.vfptr[1] = B_fun_d;   //对A的虚表进行改写

	this->m_b = b;
	printf(" B constructor function , this->b = %d\n", this->m_b);
	
}

//B的析构函数
void Destructor_B(B* this)
{
	Destructor_A(&(this->m_base));

	printf(" B destructor function \n");
}


// B的成员函数
void Fun_Member_B_VOID(B* this)  //A::funa();
{
	printf("this is B::fun_a(void)\n");
}

void Fun_Member_B_INT(B* this, int n)  //A::funb(int n);
{
	printf("this is B::fun_b(int)\n");
}

void Fun_Member_B_DOUBLE(B* this, double n) //A::func(double n);
{
	printf("this is B::fun_c(double)\n");
}

// B的虚函数
void Fun_Virtual_Member_B_INT(B* this, int n) //virtual A::fund();
{
	
	printf("this is B::fun_d(int)\n");
}
void Fun_Virtual_Member_B_DOUBLE(B* this, double n) //virtual A::fune();
{
	printf("this is B::fun_e(double)\n");
}