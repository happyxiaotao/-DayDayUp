
#include "unionset.h"

UnionSet::UnionSet(int size)
{
	_v.resize(size, -1);
}

int UnionSet::GetRoot(int index)
{
	int root = index - 1;
	while (_v[root] >= 0)
		root = _v[root];
	return root;
}

int UnionSet::GetCountFriends(int index)
{
	int root = GetRoot(index);

	return -_v[root];
}


void UnionSet::UnionFriends(int index1, int index2)
{
	int root1 = GetRoot(index1);
	int root2 = GetRoot(index2);

	if (root1 != root2)
	{
		int count = GetCountFriends(index2);
		_v[root2] = root1;
		_v[root1] -= count;
	}
}


