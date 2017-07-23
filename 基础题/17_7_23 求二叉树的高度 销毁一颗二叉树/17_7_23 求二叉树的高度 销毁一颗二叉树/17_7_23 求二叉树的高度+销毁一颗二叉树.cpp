/*
题目描述：
1，求二叉树的高度
2，销毁一颗二叉树
*/

/*
思路：
1，利用递归，获取根结点左右子树的高度，然后选择较大的+1节课。
2，利用递归，先销毁子树，在销毁根结点。
*/

#include <iostream>
#include <cassert>

struct  BinaryTreeNode
{
	BinaryTreeNode(int data)
		: m_data(data)
		, m_pLeft(nullptr)
		, m_pRight(nullptr)
	{}

	int m_data;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

class BinaryTree
{
	typedef BinaryTreeNode Node;
public:
	BinaryTree()
		: m_pRoot(nullptr)
	{}

	~BinaryTree()
	{
		_Destroy(m_pRoot);
	}

	size_t Get_Height()
	{
		return _Get_Height(m_pRoot);
	}
private:
	size_t _Get_Height(Node *root);
	void _Destroy(Node *root);
private:
	Node *m_pRoot;
};

size_t BinaryTree::_Get_Height(Node *root)
{
	if (nullptr == root)
		return 0;
	
	size_t height_left = _Get_Height(root->m_pLeft);
	size_t height_right = _Get_Height(root->m_pRight);

	return height_left > height_right : height_left + 1 ? height_right + 1;
}

void BinaryTree::_Destroy(Node *root)
{
	if (nullptr == root)//空树时
		return;
	
	if (root->m_pLeft)  //销毁左子树
		_Destroy(root->m_pLeft);
	if (root->m_pRight)  //销毁右子树
		_Destroy(root->m_pRight);

	//最后销毁根结点
	delete root;
	root = nullptr;
}

int main()
{
	system("pause");
	return 0;
}