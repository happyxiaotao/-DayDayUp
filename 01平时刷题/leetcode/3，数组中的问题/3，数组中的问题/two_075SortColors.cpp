

#if 0

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


//	��������
class Solution_1 {
public:
	//ʱ�临�Ӷȣ�O��N��
	//�ռ临�Ӷȣ�O��K=3��
	void sortColors(vector<int>& nums) {

		int length = nums.size();
		int color[3] = { 0 };
		int i = 0;
		for (; i < length; i++)
		{
			assert(nums[i] >= 0 && nums[i] <= 2);
			color[nums[i]]++;
		}

		i = 0;
		for (int j = 0; j < 3; j++)
		{
			while (color[j]--)
				nums[i++] = j;
		}
	}
};


//��·����
class Solution_2 {
public:
	//һ����·����
	//ʱ�临�Ӷȣ�O��N��
	//�ռ临�Ӷȣ�O��1��
	void sortColors(vector<int>& nums) {

		int zero = -1;  //��¼0���±�,nums[0..zero] == 0
		int two = nums.size();  //��¼2���±�,nums[two...nums.size()] == 2
		int i = 0; //nums[zero+1...two-1] == 1

		while (i < two)
		{
			if (nums[i] == 1) //�������
				i++;
			else if (nums[i] == 2)
				swap(nums[i], nums[--two]); //���ڲ�ȷ����ʱnums[two]��ֵ�����Բ��ı�i��������һ��ѭ���ж�
			else
			{
				assert(nums[i] == 0);  //����
				swap(nums[i], nums[++zero]);
				i++;    //��ʱnums[zero]��ֵһ��Ϊ1������i++��������һ��Ԫ�ص��ж�
			}
		}
	}
};

//��̬����
class Solution {
public:
	//ʱ�临�Ӷȣ�O��N��
	//�ռ临�Ӷȣ�O��1��
	void sortColors(vector<int>& nums) {

		int i = 0;
		int j = 0;
		int k = 0;

		for (int cur = 0; cur < nums.size(); cur++)
		{
			if (nums[cur] == 0)
			{
				nums[k++] = 2;
				nums[j++] = 1;
				nums[i++] = 0;
			}
			else if (nums[cur] == 1)
			{
				nums[k++] = 2;
				nums[j++] = 1;
			}
			else
			{
				assert(nums[cur] == 2);
				nums[k++] = 2;
			}
		}
	}
};


#endif