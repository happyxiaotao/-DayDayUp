#if 0

#include <iostream>

char* GetMaxSubStr(char* str, int *maxSubLen)
{
	int hash[256]; //hash记录每个字符的最近的出现位置
	int strLen = 0;		//原字符串长度
	int i = 0;
	int currentStart = 0;  //当前遍历的子串的开头
	int currentLength = 0;  //当前遍历子串的长度
	int maxStart = 0;		//最大子串的开头
	int maxEnd = 0;		//最大子串的结尾
	char *maxSubStart = NULL;

	memset(hash, -1, sizeof(char) * 256); //初始化为-1，表示没有遍历到该字符

	strLen = strlen(str); //计算原串长度

	for (i = 0; i<strLen; i++)	//遍历一次
	{
		if (currentStart > hash[str[i]]) //如果没有重复
		{
			hash[str[i]] = i;  //更新字符str[i]最近出现的位置
		}
		else
		{
			currentLength = i - currentStart; //当前长度
			if (currentLength > maxEnd - maxStart)//如果当前长度最长
			{
				maxEnd = i;
				maxStart = currentStart;
			}
			currentStart = hash[str[i]] + 1; //更新当前最长的起点
			hash[str[i]] = i; //更新字符出现的位置
		}
	}
	if (0 == maxEnd)
	{
		*maxSubLen = maxEnd - maxStart;
		maxSubStart = str + maxStart;
	}
	else  //没有重复的子串，返回原串
	{
		maxSubStart = str;
		*maxSubLen = strLen;
	}

	return maxSubStart;
}

#endif