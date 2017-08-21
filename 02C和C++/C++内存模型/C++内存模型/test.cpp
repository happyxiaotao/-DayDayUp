/*
test,cpp左键 
--> C/C++ 
--> 命令行  
--> 其它选项：
--> /d1 reportAllClassLayout（打印所有类）
	/d1 reportSinglelassLayoutXXX（XXX类名，打印指定类）

写好类之后，在运行之前打印信息。
*/

/*
重要基础：
1，对象的内存空间，只包含：非静态成员变量，虚表指针。
	不包含：成员函数，静态成员变量
2，虚表指针是个二级指针，指向一个指针数组。
3，如果派生类重写了基类中的虚函数，那么派生类中的虚表对应的指针元素，
	将不在指向基类的虚函数，指向派生类重写的那个虚函数。

*/

#include <iostream>
using namespace std;

//#include "Base.h"
//#include "多重继承.h"
//#include "虚拟继承.h"

class A
{
	int a;
	virtual void funa() { cout << "funa\n"; }
	virtual int funb() { cout << "A funb\n" << endl; return 1; }
};

//class B : virtual public A
class B : public A
{
	int b;
	virtual void funb(int a) { cout << "B funb\n"; }
	virtual void func() { cout << "func\n"; }
};

int fun(int a);
int main()
{


	B tb;
	A ta;
	A* pa = &tb;

	fun(10);

	cout << (int)pa << endl;
	cout << (int)&tb << endl;

	system("pause");
	return 0;
}