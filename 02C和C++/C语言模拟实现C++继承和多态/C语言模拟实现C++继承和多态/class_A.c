
#include "class_A.h"


//A�Ĺ��캯��
void Constructor_A(A* this, int a)
{
	//����������ָ��ָ���Ӧ�ĺ���
	A_fun_a = Fun_Member_A_VOID;
	A_fun_b = Fun_Member_A_INT;
	A_fun_c = Fun_Member_A_DOUBLE;

	this->vfptr = vftable_A;  //ָ�����
	vftable_A[0] = Fun_Virtual_Member_A_INT;  //���ָ���Ӧ����
	vftable_A[1] = Fun_Virtual_Member_A_DOUBLE; //���Ԫ��ָ���Ӧ����
	vftable_A[2] = Fun_Virtual_Member_A_FLOAT; //���Ԫ��ָ���Ӧ����

	A_fun_d = Fun_Virtual_Member_A_INT;
	A_fun_e = Fun_Virtual_Member_A_DOUBLE;
	A_fun_f = Fun_Virtual_Member_A_FLOAT;

	this->m_a = a;
	printf(" A constructor  function, this->a = %d\n", this->m_a);
}

//A����������
void Destructor_A(A* this)
{
	this->vfptr = NULL;
	printf(" A destructor  function\n");
}


// A�ĳ�Ա����
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

// A���麯��
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