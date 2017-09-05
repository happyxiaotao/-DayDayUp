
#if

#include <iostream>
#include <vector>
using namespace std;

//给定一个字符，只看其中的数字和字母，忽略大小写，判断这个字符串是否是回文串
// A man, a plan, a canal; Panama  是回文串


class Solution {
	//1，空串是回文串
public:
	//利用对装指针
	//时间复杂度：O（lgN）
	//空间复杂度：O（1）
	bool isPalindrome(string s) {
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
			while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
			while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
			if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
		}

		return true;
	}
};

#endif