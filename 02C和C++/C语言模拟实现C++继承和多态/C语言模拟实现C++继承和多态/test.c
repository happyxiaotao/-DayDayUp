
#include <stdio.h>
#include <stdlib.h>

/*
--C����ģʽʵ��C++�̳кͶ�̬��

��ʾ��Cʵ��һ��struct A��struct B������һ��int��Աa��b��
Ҫ��ﵽB�̳���A��Ч����Ҳ����B�������һ��A�������ܴﵽ��̬��Ч����
Ҳ����һ��A*pָ��A������A�ĺ�����ָ��B���õ���B�ĺ�����
*/


#include "class_A.h"
#include "class_B.h"

//���Է�װ
void Test_Encapsulation()
{
	A classA;

	Constructor_A(&classA, 10);

	A_fun_a(&classA);
	A_fun_b(&classA, 10);
	A_fun_c(&classA, 10.0);
	A_fun_d(&classA, 10);
	A_fun_e(&classA, 10.0);

	Destructor_A(&classA);
}

//���Լ̳�
void Test_Inheritance()
{
	A classA;
	B classB;

	Constructor_A(&classA, 10); 
	Constructor_B(&classB, 10, 20);

	A_fun_a(&classA);
	A_fun_b(&classA, 10);
	A_fun_c(&classA, 10.0);
	A_fun_d(&classA, 10);
	A_fun_e(&classA, 10.0);

	B_fun_a(&classB);
	B_fun_b(&classB, 10);
	B_fun_c(&classB, 10.0);
	B_fun_d(&classB, 10);
	B_fun_e(&classB, 10.0);

	Destructor_A(&classA);
	Destructor_B(&classB);
}

//���Զ�̬
void Test_polymorphism()
{
	B b;
	Constructor_B(&b);

	A_fun_a(&b.m_base);
	A_fun_b(&b.m_base, 10);
	A_fun_c(&b.m_base, 10.0);
	A_fun_d(&b.m_base, 10);
	A_fun_e(&b.m_base, 10.0);

	Destructor_B(&b);
}


int fun1(int a)
{
	return a;
}


int main()
{

//���Է�װ
//	Test_Encapsulation();
//���Լ̳�
//	Test_Inheritance();
//���Զ�̬
	Test_polymorphism();

	system("pause");
	return 0;
}