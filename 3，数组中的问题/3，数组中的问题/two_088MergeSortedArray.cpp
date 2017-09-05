
#if 0

#include <iostream>
#include <vector>
using namespace std;

class Solution_1 {
public:
	//利用临时数组
	//时间复杂度：O（M+N）
	//空间复杂度：O（M+N）
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
	//时间复杂度：O（N）
	//空间复杂度：O（1）
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		//从后往前赋值
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