/*
test,cpp��� 
--> C/C++ 
--> ������  
--> ����ѡ�
--> /d1 reportAllClassLayout����ӡ�����ࣩ
	/d1 reportSinglelassLayoutXXX��XXX��������ӡָ���ࣩ

д����֮��������֮ǰ��ӡ��Ϣ��
*/

/*
��Ҫ������
1��������ڴ�ռ䣬ֻ�������Ǿ�̬��Ա���������ָ�롣
	����������Ա��������̬��Ա����
2�����ָ���Ǹ�����ָ�룬ָ��һ��ָ�����顣
3�������������д�˻����е��麯������ô�������е�����Ӧ��ָ��Ԫ�أ�
	������ָ�������麯����ָ����������д���Ǹ��麯����

*/

#include <iostream>
using namespace std;

//#include "Base.h"
//#include "���ؼ̳�.h"
//#include "����̳�.h"

class A
{
	int a;
	virtual void funa() { cout << "funa\n"; }
	virtual void funb() { cout << "A funb\n" << endl; }
};

class B : virtual public A
{
	int b;
	virtual void funb() { cout << "B funb\n"; }
	virtual void func() { cout << "func\n"; }
};

int main()
{


	B tb;
	A* pa = &tb;

	cout << (int)pa << endl;
	cout << (int)&tb << endl;

	system("pause");
	return 0;
}