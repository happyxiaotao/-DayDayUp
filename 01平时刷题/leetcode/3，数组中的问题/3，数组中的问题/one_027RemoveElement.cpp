

#if 0

//给定一个数组nums和一个数值val.将数组中所有
//等于val的元素删除，并且返回剩余元素的个数

#include <iostream>
#include <vector>
using namespace std;

class Solution_1 {
public:
	//时间复杂度：O（N）
	//空间复杂度：O（N）
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
	//时间复杂度：O（N）
	//空间复杂度：O（1）
	int removeElement(vector<int>& nums, int val) {

		vector<int>::iterator iter = nums.begin();
		while (iter != nums.end())
		{
			if (*iter == val)
			{
				//iter = nums.erase(iter); //iter指向删除元素的下一位置
				nums.erase(iter); //因为是数组，所以可以不用重新返回
				--iter;  //自减一次，消除后面自加的影响
			}
			iter;
		}

		return nums.size();
	}
};

#endif