#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct BinaryTreeNode
{
public:
	BinaryTreeNode(const T& data = T())
		: m_data(data)
		, m_pLeft(nullptr)
		, m_pRight(nullptr)
	{}
public:
	T m_data;
	BinaryTreeNode<T> *m_pLeft;
	BinaryTreeNode<T> *m_pRight;
};

template <typename T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;

public:
	BinaryTree()
		: m_pRoot(nullptr)
	{}
	//�������
	void Level_Order();
private:
	Node *m_pRoot;
};

/*
��ͼ��⣺
1���Ƚ����ڵ�����У�
2������ѭ�������׽������У������ֵ��
3���������Һ��ӽڵ�����У�
4������2-3ѭ����ֱ������Ϊ��
*/
template <typename T>
void BinaryTree<T>::Level_Order()
{
	if (m_pRoot)
	{
		//����������Ϊ��ʱ
		queue<Node*> q;
		q.push(m_pRoot);

		while (!q.empty())
		{
			Node* pTemp = q.front();
			q.pop();
			cout << pTemp->m_data << " ";

			if (pTemp->m_pLeft)
				q.push(pTemp->m_pLeft);
			if (pTemp->m_pRight)
				q.push(pTemp->m_pRight);
		}
	}
	cout << endl;
}

int main()
{

	

	system("pause");
	return 0;
}