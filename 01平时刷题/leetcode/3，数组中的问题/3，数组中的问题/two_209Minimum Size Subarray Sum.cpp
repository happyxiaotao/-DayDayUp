
#if 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//˼·��˫��������
	//ʱ�临�Ӷȣ�O��N��
	//�ռ临�Ӷȣ�O��1��

	int minSubArrayLen(int s, vector<int>& nums) {

		int res = nums.size() + 1;
		int left = 0;
		int right = -1;//[left...right]Ϊ��������
		int sum = 0; //[left...right]�ĺ�

		while (left < nums.size())
		{
			if (right + 1 < nums.size() && sum < s)
				sum += nums[++right];
			else
				sum -= nums[left++];
			if (sum >= s)
				res = min(res, right - left + 1);
		}

		if (res == nums.size() + 1)
			res = 0;
		return res;
	}
};

int main()
{
	vector<int> nums = {2, 3, 1, 2, 4, 3};
	int s = 7;

	Solution solution;
	int ret = solution.minSubArrayLen(s, nums);

	cout << ret << endl;
	return 0;
}


#endif