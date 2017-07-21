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
	//层序遍历
	void Level_Order();
private:
	Node *m_pRoot;
};

/*
画图理解：
1，先将根节点入队列，
2，进入循环，队首结点出队列，输出其值。
3，将其左右孩子节点入队列，
4，进行2-3循环，直到队列为空
*/
template <typename T>
void BinaryTree<T>::Level_Order()
{
	if (m_pRoot)
	{
		//当二叉树不为空时
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