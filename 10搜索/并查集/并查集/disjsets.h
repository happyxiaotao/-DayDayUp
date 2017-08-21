#pragma once

#include <iostream>
using namespace std;
#include <vector>
class DisjSets
{
public:
	DisjSets(int size = 5)
	{
		_v.resize(size);
		for (int i = 0; i < size; i++)
			_v[i] = -1;
	}

	//��ȡ��
	int find(int root)
	{
		while (_v[root] >= 0)
			root = _v[root];
		return root;
	}

	//��ȡ����
	int getNumber(int root)
	{
		root = find(root);
		return -_v[root];
	}

	//�ϲ��������鼯�� ����С�ϲ�
	void unionSets(int root1, int root2)
	{
		root1 = find(root1);
		root2 = find(root2);

		if (root1 == root2)
			return;

		int num1 = getNumber(root1);
		int num2 = getNumber(root2);

		if (num1 > num2)
		{
			_v[root2] = root1;
			_v[root1] -= num2;
		}
		else
		{
			_v[root1] = root2;
			_v[root2] -= num1;
		}
	}

private:
	std::vector<int> _v;
};


