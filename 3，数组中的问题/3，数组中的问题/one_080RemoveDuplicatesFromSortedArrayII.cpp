
#if 0

//������������ౣ�������ظ���Ԫ��

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int length = nums.size();
		if (length < 2)
			return length;
		int i = 0;
		int k = 0;
		bool flag = false; //flagΪtrue��ʾĳ��Ԫ���Ѿ�������2��

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