#pragma once

#include "Base.h"
/* ����̳���� */


//����̳�
class Derived_1 : virtual public Base
{
	int c;

	virtual void VFun1();
	virtual void VFun4();
};
////������̳�
//class Derived : virtual public Derived_1
//{
//	int d;
//};
//���̳�
class Derived_2 : virtual public Base
{
	int d; 

	virtual void VFun2();
	virtual void VFun5();
};


//��������̳�
class Derived : virtual public Derived_1, Derived_2
{
	int e; 

	virtual void VFun6();
};

