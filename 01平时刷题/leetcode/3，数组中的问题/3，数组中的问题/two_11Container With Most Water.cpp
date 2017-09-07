
#if 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//思路：对撞指针
	//时间复杂度：O（lgN）
	//空间复杂度：O（1）
	int maxArea(vector<int>& height) {

		int left = 0;
		int right = height.size() - 1;
		int water = 0;
		while (left < right)
		{
			int h = min(height[left], height[right]);
			water = max(water, (right - left)*h);
			while (height[left] <= h && left < right)
				left++;
			while (height[right] <= h && left < right)
				right--;
		}
		return water;
	}
};


#endif 