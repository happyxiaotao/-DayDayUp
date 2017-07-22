/*
求二叉树叶子节点的个数 / 求二叉树第k层的节点个数
*/

#include <iostream>
#include <cassert>

struct Node
{
	int _val;
	Node* _pRight;
	Node* _pLeft;
};

size_t Get_Leaves(const Node* pNode)
{
	if (nullptr == pNode)
		return 0;

	if ((nullptr == pNode->_pLeft) && (nullptr == pNode->_pRight))
		return 1;

	size_t count_left = Get_Leaves(pNode->_pLeft);
	size_t count_right = Get_Leaves(pNode->_pRight);

	return (count_left+count_right);
}

size_t Get_K_Floor_Node(const Node* pNode, int k)
{
	if ((1 > k) || (nullptr == pNode)) //k<1或空树
		return 0; 

	if (1 == k)  //当前层，返回1 
		return 1;

	size_t count_left = Get_K_Floor_Node(pNode->_pLeft, k-1);
	size_t count_right = Get_K_Floor_Node(pNode->_pRight, l-1);

	return count_left + count_right;
}