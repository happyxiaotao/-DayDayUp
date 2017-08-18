#pragma once

#include <iostream>
using namespace std;
#include <vector>
class UnionSet
{
public:
	UnionSet(int size = 5);

	//获取根
	int GetRoot(int index);

	//获取朋友圈个数
	int GetCountFriends(int index);

	//合并两个朋友圈
	void UnionFriends(int index1, int index2);

private:
	std::vector<int> _v;
};


