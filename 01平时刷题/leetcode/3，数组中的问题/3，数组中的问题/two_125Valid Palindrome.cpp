
#if

#include <iostream>
#include <vector>
using namespace std;

//����һ���ַ���ֻ�����е����ֺ���ĸ�����Դ�Сд���ж�����ַ����Ƿ��ǻ��Ĵ�
// A man, a plan, a canal; Panama  �ǻ��Ĵ�


class Solution {
	//1���մ��ǻ��Ĵ�
public:
	//���ö�װָ��
	//ʱ�临�Ӷȣ�O��lgN��
	//�ռ临�Ӷȣ�O��1��
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