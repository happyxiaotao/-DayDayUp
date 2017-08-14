#pragma once

#include "Base.h"
/* 多重继承情况 */

//单继承
class Derived_1 : public Base
{
	int c;

	virtual void VFun1();

	virtual void VFun4();
};
//单继承
class Derived_2 : public Base
{
	int d;

	virtual void VFun2();

	virtual void VFun5();
};
//菱形继承
class Derived : public Derived_1, Derived_2
{
	int e;

	virtual void VFun6();
};
