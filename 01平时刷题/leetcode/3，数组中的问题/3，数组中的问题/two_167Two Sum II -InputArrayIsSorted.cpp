
#if 0

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//从两边往中间，对撞指针
	//时间复杂度：O（N）
	//空间复杂度：O（1）
	vector<int> twoSum(vector<int>& numbers, int target) {

		int left = 0;
		int right = numbers.size() - 1;
		vector<int> index;

		while (left < right)
		{
			int sum = numbers[left] + numbers[right];
			if (sum > target)
				right--;
			else if (sum < target)
				left++;
			else //sum == target
			{
				index.push_back(left + 1);
				index.push_back(right + 1);
				break;
			}
		}
		return index;
	}
};

#endif