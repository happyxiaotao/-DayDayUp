

#if 0

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


//	计数排序
class Solution_1 {
public:
	//时间复杂度：O（N）
	//空间复杂度：O（K=3）
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


//三路快排
class Solution_2 {
public:
	//一次三路快排
	//时间复杂度：O（N）
	//空间复杂度：O（1）
	void sortColors(vector<int>& nums) {

		int zero = -1;  //记录0的下标,nums[0..zero] == 0
		int two = nums.size();  //记录2的下标,nums[two...nums.size()] == 2
		int i = 0; //nums[zero+1...two-1] == 1

		while (i < two)
		{
			if (nums[i] == 1) //往后遍历
				i++;
			else if (nums[i] == 2)
				swap(nums[i], nums[--two]); //由于不确定此时nums[two]的值，所以不改变i，放入下一次循环判断
			else
			{
				assert(nums[i] == 0);  //断言
				swap(nums[i], nums[++zero]);
				i++;    //此时nums[zero]的值一定为1，所以i++，进行下一个元素的判断
			}
		}
	}
};

//变态做法
class Solution {
public:
	//时间复杂度：O（N）
	//空间复杂度：O（1）
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