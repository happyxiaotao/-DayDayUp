
/*
��Ŀ������
Ԫ�س�ջ����ջ˳��ĺϷ��ԡ��磺��ջ�����У�1,2,3,4,5������ջ����Ϊ��4,5,3,2,1������Ϸ���
��ջ�����У�1,2,3,4,5������ջ����Ϊ��4,5,2,3,1�����򲻺Ϸ���

˼·��
��������һ��������ջ�ռ䡣
1���ѵ�һ������v1�е��������ѹ��ջ�У�ѹ��Ĺ����аѵڶ�������v2��Ԫ����ջ��Ԫ�رȽϡ�
2�������ͬ�����ջ��ͬʱ,v2�±������ƣ�׼��������һ�αȽϡ�
3�������ͬ����v1������������ջ��ֱ������1�е���������û������Ϊֹ��
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
bool Check_Out_Stack_Order(const vector<T>& v_1, const vector<T> v_2)
{
	//�������и�������ͬ
	if (v_1.size() != v_2.size()) 
		return false;

	//��ʱv_1,v_2��Ԫ�ظ����϶���ͬ
	stack<T> s;			 //����ջ�����v_2���е�ջ�������Ϊԭջ
	size_t index_1 = 0;  //��Ϊv_1���±�
	size_t index_2 = 0;  //��Ϊv_2���±�
	while (index_2 < v_2.size())    //������v_1,v_2��Ϊ�յ����
	{
		//��sΪ��,����ջ��Ԫ�ز�����v_2[index_2]ʱ��v_1��Ԫ��Ҫ��ͣ���븨��ջ��ֱ��û��Ԫ�ؿ���
		while (s.empty() || s.top() != v_2[index_2])
		{
			if (index_1 < v_1.size())
				s.push(v_1[index_1++]);
			else
				return false;  //��v_1������ȫ����ջ������û����v_2�з�������ȵģ�˵�����������к��е����ݲ�һ��
		}
		//��ʱ��s.top()=v_2[index_2]��˵��ԭջ�˴��г�ջ�������õ�v_2�е�v_2[index]��
		s.pop();
		++index_2;
	}
	if (s.empty())
		return true;
	else
		return false;
}	

int main()
{	
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 4,5,3,2,1 };
	vector<int> v3 = { 4,5,2,3,1 };

	cout << "v1 �� v2�Ƿ������ջ����ջ�ĺϷ��ԣ�";
	if (Check_Out_Stack_Order(v1, v2))
		cout << " ����" << endl;
	else
		cout << "������" << endl;

	cout << "v1 �� v3�Ƿ������ջ����ջ�ĺϷ��ԣ�";
	if (Check_Out_Stack_Order(v1, v3))
		cout << " ����" << endl;
	else
		cout << "������" << endl;

	system("pause");
	return 0;
}