
#include <stdio.h>
#include <stdlib.h>

/*
--C语言模式实现C++继承和多态。

提示：C实现一个struct A和struct B各包含一个int成员a和b，
要求达到B继承了A的效果，也就是B里面包含一个A。并且能达到多态的效果，
也就是一个A*p指向A调的是A的函数，指向B调用的是B的函数。
*/


#include "class_A.h"
#include "class_B.h"

//测试封装
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

//测试继承
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

//测试多态
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

//测试封装
//	Test_Encapsulation();
//测试继承
//	Test_Inheritance();
//测试多态
	Test_polymorphism();

	system("pause");
	return 0;
}