

#if 0

//����һ������nums��һ����ֵval.������������
//����val��Ԫ��ɾ�������ҷ���ʣ��Ԫ�صĸ���

#include <iostream>
#include <vector>
using namespace std;

class Solution_1 {
public:
	//ʱ�临�Ӷȣ�O��N��
	//�ռ临�Ӷȣ�O��N��
	int removeElement(vector<int>& nums, int val) {

		vector<int> temp;

		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != val)
				temp.push_back(nums[i]);
		nums.swap(temp);

		return nums.size();
	}
};

class Solution_2 {
public:
	//ʱ�临�Ӷȣ�O��N��
	//�ռ临�Ӷȣ�O��1��
	int removeElement(vector<int>& nums, int val) {

		vector<int>::iterator iter = nums.begin();
		while (iter != nums.end())
		{
			if (*iter == val)
			{
				//iter = nums.erase(iter); //iterָ��ɾ��Ԫ�ص���һλ��
				nums.erase(iter); //��Ϊ�����飬���Կ��Բ������·���
				--iter;  //�Լ�һ�Σ����������Լӵ�Ӱ��
			}
			iter;
		}

		return nums.size();
	}
};

#endif