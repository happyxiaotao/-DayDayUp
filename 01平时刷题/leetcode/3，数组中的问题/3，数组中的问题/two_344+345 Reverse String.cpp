
#if 0

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	//题目：翻转字符串
	//思路：对撞指针
	//时间复杂度：O（lgN）
	//空间复杂度：O（1）
	string reverseString(string s) {

		int left = 0;
		int right = s.length() - 1;
		string temp = s;
		while (left < right)
			swap(temp[left++], temp[right--]);
		return temp;
	}

	//题目：翻转字符串中的元音字母
	//思路：对撞指针
	//时间复杂度：O（lgN）
	//空间复杂度：O（1）
	string reverseVowels_1(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			i = s.find_first_of("aeiouAEIOU", i);
			j = s.find_last_of("aeiouAEIOU", j);
			if (i < j) {
				swap(s[i++], s[j--]);
			}
		}
		return s;
	}


	//题目：翻转字符串中的元音字母
	//思路：对撞指针
	//时间复杂度：O（lgN）
	//空间复杂度：O（1）
	inline bool isVowel(char ch)
	{
		ch = tolower(ch);
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			return true;
		return false;
	}

	string reverseVowels(string s) {

		int left = 0;
		int right = s.length() - 1;
		string temp = s;
		while (left < right)
		{
			while (!isVowel(temp[left]) && left < right)
				left++;
			while (!isVowel(temp[right]) && left < right)
				right--;
			if (left < right)
				swap(temp[left], temp[right]);
			left++;
			right--;
		}
		return temp;
	}
};

#endif