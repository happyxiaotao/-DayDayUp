

#if 0

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	//˼·��˫�������� + hashӳ��
	//ʱ�临�Ӷȣ�O��N��
	//�ռ临�Ӷȣ�O��256*2��
	vector<int> findAnagrams(string s, string p) {

		vector<int> res;
		if (s.length() < p.length())    //ԭ��s�ĳ��Ȳ���С���Ӵ�p�ĳ���
			return res;

		int left = 0, right = p.length() - 1;//[left...right]Ϊ��������
		vector<int> vs(256, 0);  //��¼�����ڻ������ڵ��ַ�����������
		vector<int> vp(256, 0);  //��¼������p�е��ַ�����������

		for (int i = 0; i < p.length(); i++)  //ͳ�Ƴ�ʼ�������ڣ��Լ��Ӵ�����Ϣ
		{
			vs[s[i]] ++;      //��Ӧ�ַ������Լ�
			vp[p[i]] ++;      //��Ӧ�ַ������Լ�
		}

		do
		{
			if (vs == vp)          //�������ߵ��ַ���������ж��Ƿ�ߵ�
				res.push_back(left);

			vs[s[++right]] ++;
			vs[s[left++]] --;     //��������������

		} while (right < s.length());

		return res;
	}
};

#endif