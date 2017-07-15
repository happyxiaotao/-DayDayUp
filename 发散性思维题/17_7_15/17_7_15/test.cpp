/*
1,设计一个类不能被继承
2.设计一个类只能在堆上创建对象。
3.设计一个类只能在栈上创建对象。
ps：以上三个问题是类似的。
*/

#include <iostream>
using namespace std;

/*
该类不能被继承:
思路：不能被继承，可以看作是，在继承的类中，无法使用子类的东西。
相当于他的子类无法调用父类的构造函数，或者无法调用父类的析构函数。
所以，可以将父类的构造函数或析构函数，声明为私有的即可。
*/
class Test1_Base
{
private:
	Test1_Base()
	{
		cout << "Test1_Base constructor function" << endl;
	}
public:
	~Test1_Base()
	{
		cout << "de" << endl;
	}
};
/*如下，如果强行继承该类，编译会出错
class Test1_Derived  : public Test1_Base
{
Test1_Derived()
{
std::cout << "Test1_Derived" << endl;
}
};
*/



/*
该类只能在堆上创建对象
思路：要使得一个类只能在堆上创建对象，就必须使得编译器无法在栈上创建空间，
或者无法释放资源，如果将构造函数设置为私有的，则也无法在堆上创建对象。
如果将析构函数设置为私有的，则也无法直接在堆上释放资源。
但是，我们可以通过新添一个资源释放函数Destroy函数封装delete操作，来避免delete权限不够的情况。
（不鞥通过新添一个init函数封装new，因为调用init函数前提是类对象已经存在）
*/
class Test2
{
public:
	void Destroy()
	{
		delete this;
	}
private:
	~Test2()
	{}
};

/*
该类只能在栈上创建对象
思路：
能在栈上分配空间：可将 T:: operator new 全部私有，
因为要在堆上分配空间，需要用到new来实现，当把new私有化，
就不能调用new T()这样的语句，这样可以达到只能在栈上来分配空间了。
*/
class Test3
{
private:
	void* operator new(size_t size);
};


int main()
{
	//	Test1_Derived d;

	Test2 t2;

	//	Test3* pt3 = new Test3;

	return 0;
}