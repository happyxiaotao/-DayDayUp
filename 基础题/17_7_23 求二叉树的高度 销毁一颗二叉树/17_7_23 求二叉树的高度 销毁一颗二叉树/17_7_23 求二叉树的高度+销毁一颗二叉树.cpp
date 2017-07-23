/*
��Ŀ������
1����������ĸ߶�
2������һ�Ŷ�����
*/

/*
˼·��
1�����õݹ飬��ȡ��������������ĸ߶ȣ�Ȼ��ѡ��ϴ��+1�ڿΡ�
2�����õݹ飬�����������������ٸ���㡣
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
	if (nullptr == root)//����ʱ
		return;
	
	if (root->m_pLeft)  //����������
		_Destroy(root->m_pLeft);
	if (root->m_pRight)  //����������
		_Destroy(root->m_pRight);

	//������ٸ����
	delete root;
	root = nullptr;
}

int main()
{
	system("pause");
	return 0;
}