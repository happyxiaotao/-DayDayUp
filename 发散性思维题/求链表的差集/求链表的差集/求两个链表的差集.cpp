/*
��Ŀ������
��֪����A��B��Ԫ�طֱ��ò���ͷ���ĵ�����洢������difference()������⼯��A��B�Ĳ��
������������ڼ���A�ĵ������С����磬������A={5,10,20,15,25,30}������B={5,15,35,25}����ɼ����A={10,20,30}�� 

������Ľṹ���Ͷ������£� 
struct node 
{ 
int elem; 
node* next; 
}; 
����ɺ���void difference(node** LA , node* LB)��


˼·��
��ٷ�
*/

/*
#include <iostream>
#include <cassert>

using namespace std;

typedef struct node
{
	node(int val = int())
		: elem(val)
		, next(nullptr)
	{}
	int elem;
	node* next;
}node;

void difference(node **LA, node *LB) //ע�⣬LA�Ƕ���ָ�룬��Ϊ�п����޸�����ͷ���ָ��
{
	assert(nullptr != LA);
	assert(nullptr != *LA);
	assert(nullptr != LB);

	node *pPre = nullptr; //ָ��pa�����ڵ�
	node *pa = *LA;		//ָ��LA�еĽڵ�
	node *pb = LB;		//ָ��LB�еĽڵ�
	node *pTemp = nullptr; //��ʱָ��

	//ѭ��LA�еĽڵ㣬ÿ�ζ���LB��Ѱ��
	while (pa)
	{
		pb = LB; //ÿ��ѭ�����¸�ֵ����LBͷ��ʼ������LB
		while (pb && (pa->elem != pb->elem))
			pb = pb->next;

		if (pb)  //˵���ҵ��ˡ���ע�⣺�˴�������pa->elem == pb->elempb��Ϊ�ж���������ΪֻҪpb��Ϊ�գ����п��ܱȽϣ�
		{
			//��ʱpb->elem == pb->elem���ҵ�������������ֵ��ͬ�Ľڵ㣬����ɾ������
			//�ж�ɾ�����Ƿ���LA��ͷ���
			if (nullptr == pPre) //ֱ�Ӷ�LA���в������޸�����ͷָ��ע��LA�Ƕ���ָ�룩
				*LA = pa->next; 
			else  //����ͷ���
				pPre->next = pa->next;

			pTemp = pa;		
			pa = pa->next; //����pa
			delete pTemp;
			pTemp = nullptr;
		}
		else	//������LB������û���ҵ���pa->elem��ͬ�Ľڵ㡣
		{
			pPre = pa;	//����ǰ���ڵ�
			pa = pa->next;	//����pa
		}
	}
}

void Test();

int main()
{
	Test();

	system("pause");
	return 0;
}

void PrintList(node *pnode)
{
	while (pnode)
	{
		cout << pnode->elem << "->";
		pnode = pnode->next;
	}
	cout << "nullptr"<< endl;
}

void Test()
{
	node *p1 = new node[10];
	node *p2 = new node[5];

	int i = 0;
	for (; i < 10; ++i)
		p1[i].elem = i;
	for (i = 0; i < 10-1; ++i)
		p1[i].next = &p1[i + 1];


	for (i = 0; i < 5; ++i)
		p2[i].elem = i * 2;
	for (i = 0; i < 5-1; ++i)
		p2[i].next = &p2[i + 1];

	node *list1 = &p1[0];
	node *list2 = &p2[0];
	PrintList(list1);//PrintList(list1);Ҳ����
	PrintList(list2);

	difference(&list1, list2);//difference(&p1, p2);������⣬������

	PrintList(list1);//PrintList(list1);Ҳ����
	PrintList(list2);
}

*/
//��������A={5,10,20,15,25,30}������B={5,15,35,25}����ɼ����A={10,20,30}�� 
#include <iostream>
using namespace std;
struct node
{
	node(int data) :elem(data), next(NULL)
	{}

	int elem;
	node* next;

};
//A={5,10,20,15,25,30
node* creat(int arr[], int size)
{
	node* phead = new node(arr[0]);//ͷ���
	node* pcur = phead;
	//node* pnew=NULL;
	for (int i = 1; i<size; i++)
	{
		node* pnew = new node(arr[i]);
		pcur->next = pnew;
		pcur = pnew;
	}
	return phead;
}
void difference(node** LA, node* LB)
{
	node* pa = *LA;
	node* pb = LB;
	node* pre = NULL;
	node* temp = NULL;
	while (pa)
	{
		pb = LB;//��֤ÿ�δ�LB�ĵ�һ���ڵ�����
		while (pb&&pb->elem != pa->elem)//Ѱ��PB�к�PA��ͬ��Ԫ��
			pb = pb->next;
		if (pb)//�ҵ���
		{

			if (NULL == pre)//PA��ͷ���
				*LA = pa->next;
			else
			{
				pre->next = pa->next;//����ǰ��ڵ�
			}
			temp = pa;
			pa = pa->next;
			free(temp);

		}
		else//û�ҵ�PA�еĵ�ǰ�ڵ㣬����Ѱ��PA����һ���ڵ�
		{
			pre = pa;
			pa = pa->next;
		}

	}

}
void print(node* l)
{
	node* pcur = l;
	while (pcur)
	{
		cout << pcur->elem << " ";
		pcur = pcur->next;

	}
	cout << endl;
}
int main()
{
	int A[] = { 5,10,20,15,25,30 };
	int B[] = { 5,15,35,25 };
	node* la = creat(A, sizeof(A) / sizeof(A[0]));
	node* lb = creat(B, sizeof(B) / sizeof(B[0]));
	difference(&la, lb);
	print(la);

	system("pause");
	return 0;
}