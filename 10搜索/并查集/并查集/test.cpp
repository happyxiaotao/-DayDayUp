/*
��������Ŀ��
��֪��n���˺�m�Ժ��ѹ�ϵ����������r����
�����������ֱ�ӻ��ӵĺ��ѣ����ѵĺ��ѵĺ��ѡ�����
����Ϊ��������ͬһ������Ȧ����д���������n������һ���ж��ٸ�����Ȧ��
���磺n = 5 �� m = 3 �� r = {{1 , 2} , {2 , 3} , {4 , 5}}��
��ʾ��5���ˣ�1��2�Ǻ��ѣ�2��3�Ǻ��ѣ�4��5�Ǻ��ѣ�
��1��2��3����һ������Ȧ��4��5������һ������Ȧ�����Ϊ2������Ȧ��
����������д�����ʱ�䡢�ռ临�Ӷȡ�
������򵥲������Ч�Ľⷨ����ʹ�ò��鼯
*/



#include "unionset.h"

void Test()
{
	UnionSet u(5);

	u.UnionFriends(1, 2);
	u.UnionFriends(4, 5);
	u.UnionFriends(2, 3);

	cout << u.GetCountFriends(1) << endl;
	cout << u.GetCountFriends(2) << endl;
	cout << u.GetCountFriends(3) << endl;
	cout << u.GetCountFriends(4) << endl;
	cout << u.GetCountFriends(5) << endl;

	cout << "��ӡ����" << endl;
	cout << u.GetRoot(1) << endl;
	cout << u.GetRoot(2) << endl;
	cout << u.GetRoot(3) << endl;
	cout << u.GetRoot(4) << endl;
	cout << u.GetRoot(5) << endl;
}


int main()
{
	Test();

	system("pause");
	return 0;
}