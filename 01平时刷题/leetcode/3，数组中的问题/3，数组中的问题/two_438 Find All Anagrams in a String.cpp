

#if 0

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	//思路：双索引技术 + hash映射
	//时间复杂度：O（N）
	//空间复杂度：O（256*2）
	vector<int> findAnagrams(string s, string p) {

		vector<int> res;
		if (s.length() < p.length())    //原串s的长度不能小于子串p的长度
			return res;

		int left = 0, right = p.length() - 1;//[left...right]为滑动窗口
		vector<int> vs(256, 0);  //记录出现在滑动窗口的字符及其个数情况
		vector<int> vp(256, 0);  //记录出现在p中的字符及其个数情况

		for (int i = 0; i < p.length(); i++)  //统计初始滑动窗口，以及子串的信息
		{
			vs[s[i]] ++;      //对应字符个数自加
			vp[p[i]] ++;      //对应字符个数自加
		}

		do
		{
			if (vs == vp)          //根据两者的字符及其个数判断是否颠倒
				res.push_back(left);

			vs[s[++right]] ++;
			vs[s[left++]] --;     //滑动窗口往后移

		} while (right < s.length());

		return res;
	}
};

#endif