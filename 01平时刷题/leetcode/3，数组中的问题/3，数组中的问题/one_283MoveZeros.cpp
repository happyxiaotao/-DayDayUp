
#if 0

#include <iostream>
#include <vector>
using namespace std;

//题目描述：将数组中的0移动到后面，非0元素的相对位置不变

class Solution_1 {
public:
	//时间复杂度：O（N）
	//空间复杂度：O（N）
	void moveZeroes(vector<int>& nums) {
		vector<int> temp;
		int i = 0;
		for (; i < nums.size(); i++)
			if (nums[i] != 0)
				temp.push_back(nums[i]);
		for (i = 0; i < temp.size(); i++)
			nums[i] = temp[i];
		for (i = temp.size(); i < nums.size(); i++)
			nums[i] = 0;
	}
};

class Solution_2 {
public:
	//时间复杂度：O（N）
	//空间复杂度：O（1）
	void moveZeroes(vector<int>& nums) {
		int k = 0;
		int i = 0;
		int length = nums.size();
		for (; i < length; i++)
			if (nums[i])
				nums[k++] = nums[i];
		for (i = k; i< length; i++)
			nums[i] = 0;
	}
};

class Solution_3 {
public:
	//时间复杂度：O（N）
	//空间复杂度：O（1）
	void moveZeroes(vector<int>& nums) {
		int k = 0;
		int length = nums.size();
		for (int i = 0; i < length; i++)
			if (nums[i])
				swap(nums[k++], nums[i]);
	}
};

class Solution_4 {
public:
	//时间复杂度：O（N）
	//空间复杂度：O（1）
	void moveZeroes(vector<int>& nums) {
		int k = 0;
		int length = nums.size();
		for (int i = 0; i < length; i++)
			if (nums[i])
				if (k != i)
					swap(nums[k++], nums[i]);
				else
					k++;
	}
};

#endif 