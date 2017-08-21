
#include "class_A.h"


//A的构造函数
void Constructor_A(A* this, int a)
{
	//将各个函数指针指向对应的函数
	A_fun_a = Fun_Member_A_VOID;
	A_fun_b = Fun_Member_A_INT;
	A_fun_c = Fun_Member_A_DOUBLE;

	this->vfptr = vftable_A;  //指向虚表
	vftable_A[0] = Fun_Virtual_Member_A_INT;  //虚表指向对应函数
	vftable_A[1] = Fun_Virtual_Member_A_DOUBLE; //虚表元素指向对应函数
	vftable_A[2] = Fun_Virtual_Member_A_FLOAT; //虚表元素指向对应函数

	A_fun_d = Fun_Virtual_Member_A_INT;
	A_fun_e = Fun_Virtual_Member_A_DOUBLE;
	A_fun_f = Fun_Virtual_Member_A_FLOAT;

	this->m_a = a;
	printf(" A constructor  function, this->a = %d\n", this->m_a);
}

//A的析构函数
void Destructor_A(A* this)
{
	this->vfptr = NULL;
	printf(" A destructor  function\n");
}


// A的成员函数
void Fun_Member_A_VOID(A* this)  //A::funa();
{
	printf("this is A::fun_a(void)\n");
}

void Fun_Member_A_INT(A* this, int n)  //A::funb(int n);
{
	printf("this is A::fun_b(int)\n");
}

void Fun_Member_A_DOUBLE(A* this, double n) //A::func(double n);
{
	printf("this is A::fun_c(double)\n");
}

// A的虚函数
void Fun_Virtual_Member_A_INT(A* this, int n) //virtual A::fund();
{
	printf("this is A::fun_d(int)\n");
}
void Fun_Virtual_Member_A_DOUBLE(A* this, double n) //virtual A::fune();
{
	printf("this is A::fun_e(double)\n");
}
void Fun_Virtual_Member_A_FLOAT(A* this, float n) //virtual A::funf();
{
	printf("this is A::fun_f(float)\n");
}