
#if 0

#include <iostream>
#include <vector>
using namespace std;

class Solution_1 {
public:
	//������ʱ����
	//ʱ�临�Ӷȣ�O��M+N��
	//�ռ临�Ӷȣ�O��M+N��
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		vector<int> temp;
		int i = 0;
		int j = 0;
		while (i < m && j < n)
		{
			/*
			if (nums1[i] < nums2[j])
				temp.push_back(nums1[i++]);
			else
				temp.push_back(nums2[j++]);
			*/
			while (i < m && nums1[i] < nums2[j])
				temp.push_back(nums1[i++]);
			while (j < n && nums1[i] >= nums2[j])
				temp.push_back(nums2[j++]);
		}

		while (i < m)
			temp.push_back(nums1[i++]);
		while (j < n)
			temp.push_back(nums2[j++]);

		swap(nums1, temp);
	}
};

class Solution_2 {
public:
	//ʱ�临�Ӷȣ�O��N��
	//�ռ临�Ӷȣ�O��1��
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		//�Ӻ���ǰ��ֵ
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;

		while (i >= 0 && j >= 0)
		{
			if (nums1[i] > nums2[j])
				nums1[k--] = nums1[i--];
			else
				nums1[k--] = nums2[j--];
		}

		while (j >= 0)
			nums1[k--] = nums2[j--];
	}
};

#endif