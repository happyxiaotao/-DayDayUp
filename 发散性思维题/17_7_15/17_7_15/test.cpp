/*
1,���һ���಻�ܱ��̳�
2.���һ����ֻ���ڶ��ϴ�������
3.���һ����ֻ����ջ�ϴ�������
ps�������������������Ƶġ�
*/

#include <iostream>
using namespace std;

/*
���಻�ܱ��̳�:
˼·�����ܱ��̳У����Կ����ǣ��ڼ̳е����У��޷�ʹ������Ķ�����
�൱�����������޷����ø���Ĺ��캯���������޷����ø��������������
���ԣ����Խ�����Ĺ��캯������������������Ϊ˽�еļ��ɡ�
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
/*���£����ǿ�м̳и��࣬��������
class Test1_Derived  : public Test1_Base
{
Test1_Derived()
{
std::cout << "Test1_Derived" << endl;
}
};
*/



/*
����ֻ���ڶ��ϴ�������
˼·��Ҫʹ��һ����ֻ���ڶ��ϴ������󣬾ͱ���ʹ�ñ������޷���ջ�ϴ����ռ䣬
�����޷��ͷ���Դ����������캯������Ϊ˽�еģ���Ҳ�޷��ڶ��ϴ�������
�����������������Ϊ˽�еģ���Ҳ�޷�ֱ���ڶ����ͷ���Դ��
���ǣ����ǿ���ͨ������һ����Դ�ͷź���Destroy������װdelete������������deleteȨ�޲����������
�����Eͨ������һ��init������װnew����Ϊ����init����ǰ����������Ѿ����ڣ�
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
����ֻ����ջ�ϴ�������
˼·��
����ջ�Ϸ���ռ䣺�ɽ� T:: operator new ȫ��˽�У�
��ΪҪ�ڶ��Ϸ���ռ䣬��Ҫ�õ�new��ʵ�֣�����new˽�л���
�Ͳ��ܵ���new T()��������䣬�������Դﵽֻ����ջ��������ռ��ˡ�
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