#pragma once

#include <iostream>
using namespace std;
#include <vector>
class UnionSet
{
public:
	UnionSet(int size = 5);

	//��ȡ��
	int GetRoot(int index);

	//��ȡ����Ȧ����
	int GetCountFriends(int index);

	//�ϲ���������Ȧ
	void UnionFriends(int index1, int index2);

private:
	std::vector<int> _v;
};


