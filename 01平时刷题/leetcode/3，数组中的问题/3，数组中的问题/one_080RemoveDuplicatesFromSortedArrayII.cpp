
#if 0

//有序数组中最多保留两个重复的元素

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int length = nums.size();
		if (length < 2)
			return length;
		int i = 0;
		int k = 0;
		bool flag = false; //flag为true表示某个元素已经出现了2次

		for (i = 1, k = 1; i < length; i++)
		{
			if (nums[i - 1] != nums[i])
			{
				nums[k++] = nums[i];
				flag = false;
			}
			else if (!flag)  //nums[i-1] == nums[i]
			{
				nums[k++] = nums[i];
				flag = true;
			}
		}
		for (i = k; i < length; i++)
			nums.pop_back();
		return k;
	}
};

#endif 