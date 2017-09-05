
#if 0

#include <iostream>
#include <vector>
using namespace std;

class Solution_1 {
public:
	//时间复杂度：O（N）
	//空间复杂度：O（1）
	int removeDuplicates(vector<int>& nums) {

		if (nums.size() == 0 || nums.size() == 1)
			return nums.size();

		vector<int>::iterator iter = nums.begin();
		int pre = *iter++;
		while (iter != nums.end())
		{
			if (*iter == pre)
			{
				nums.erase(iter);
				iter--;
			}
			else
				pre = *iter;
			iter++;
		}

		return nums.size();
	}
};


class Solution_2 {
public:
	//时间复杂度：O（N）
	//空间复杂度：O（1）
	int removeDuplicates(vector<int>& nums) {

		int length = nums.size();
		if (length < 2)
			return length;
		int k = 1;
		int i = 0;
		for (i = 1; i < length; i++)
		{
			if (nums[i - 1] != nums[i])
			{
				nums[k++] = nums[i];
			}
		}
		for (i = k; i < length; i++)
			nums.pop_back();

		return k;
	}
};

#endif