#pragma once

#include "Base.h"
/* 剞攜樟創①錶 */


//等剞樟創
class Derived_1 : virtual public Base
{
	int c;

	virtual void VFun1();
	virtual void VFun4();
};
////謗脯剞樟創
//class Derived : virtual public Derived_1
//{
//	int d;
//};
//等樟創
class Derived_2 : virtual public Base
{
	int d; 

	virtual void VFun2();
	virtual void VFun5();
};


//鎂倛剞攜樟創
class Derived : virtual public Derived_1, Derived_2
{
	int e; 

	virtual void VFun6();
};

