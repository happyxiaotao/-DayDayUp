
#if 1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution_1 {
public:
	//˫��������
	//ʱ�临�Ӷȣ�O��N��
	//�ռ临�Ӷȣ�O��256��
	int lengthOfLongestSubstring(string s) {

		int left = 0, right = -1;   //��������Ϊ[left...right]
		int hash[256] = { 0 };  //hashӳ�䣬�����ж��ַ��Ƿ����
		int res = 0;

		while (left < s.size())
		{
			if ((1 + right) < s.size() && hash[s[right + 1]] == 0)
				hash[s[++right]] ++;
			else
			{
				res = max(res, right - left + 1);
				hash[s[left++]] --;
			}
		}

		return res;
	}
};


class Solution_2 {
public:
	//��̬�滮
	//ʱ�临�Ӷȣ�O��N��
	//�ռ临�Ӷȣ�O��256��
	int lengthOfLongestSubstring(string s) {
		vector<int> dict(256, -1);
		int maxLen = 0, start = -1;
		for (int i = 0; i != s.length(); i++) {
			if (dict[s[i]] > start)
				start = dict[s[i]];
			dict[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}
		return maxLen;
	}
};

#endif 