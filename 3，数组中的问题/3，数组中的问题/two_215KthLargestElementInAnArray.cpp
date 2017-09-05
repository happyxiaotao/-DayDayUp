
#if 0

#include <iostream>
#include <vector>
using namespace std;

//快排练练手
void QuickSort(vector<int>& nums, int left, int right)
{
	if (left >= right)
		return;
	int pivot = nums[left];
	int i = left;
	int j = right;
		
	while (i < j)
	{
		while (i < j && nums[j] >= pivot)
			j--;
		nums[i] = nums[j];

		while (i < j && nums[i] <= pivot)
			i++;
		nums[j] = nums[i];
	}
	nums[i] = pivot;

	QuickSort(nums, left, i);
	QuickSort(nums, i+1, right);
}

//根据快排改的，只在需要的区间区查找，并不排序
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		return myfind(nums, k, 0, nums.size() - 1);
	}
	int myfind(vector<int>& nums, int k, int left, int right)
	{
		if (left == right && left == nums.size() - k)
			return nums[left];
		int pivot = nums[left];
		int i = left;
		int j = right;

		while (i < j)
		{
			while (i < j && nums[j] >= pivot)
				j--;
			nums[i] = nums[j];
			while (i < j && nums[i] <= pivot)
				i++;
			nums[j] = nums[i];
		}
		nums[i] = pivot;

		if (i > nums.size() - k)
			return myfind(nums, k, left, i);
		else if (i < nums.size() - k)
			return myfind(nums, k, i + 1, right);
		else  //i == nums.size()-k
			return nums[i];
	}
};


//终极版：快排+二分
class Solution {
public:
	//时间复杂度：O（N）
	//空间复杂度：O（1）
	int partition(vector<int>& nums, int left, int right, int pivot)
	{
		int value = nums[pivot];
		swap(nums[pivot], nums[right]);
		int store = left;
		for (int i = left; i <= right - 1; i++)
		{
			if (nums[i]>value)
			{
				swap(nums[store], nums[i]);
				store++;
			}
		}
		swap(nums[right], nums[store]);
		return store;
	}

	int select(vector<int>& nums, int left, int right, int k) {
		while (left != right)
		{
			int pivot = (left + right) / 2;
			int ind = partition(nums, left, right, pivot);
			if (ind == k - 1)
				return nums[k - 1];
			else if (ind<k - 1)
				left = ind + 1;
			else
				right = ind;
		}
		return nums[left];
	}

	int findKthLargest(vector<int>& nums, int k) {
		return select(nums, 0, nums.size() - 1, k);
	}
};


#endif