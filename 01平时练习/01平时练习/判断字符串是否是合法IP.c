 0
/*
题目：判断一个字符串是否是合法的IP
思路：
IP字符串是一个点分十进制。
利用atoi将字符串转化为数字

传入的参数char *ip;
1，ip为NULL或者 ip的长度大于12+3=15
2，发现除了数字字符、点字符之外的字符。
3，数字字符表示的数超出了0~255之外。

*/

#if 0

#include <stdio.h>  
#include <string.h>		// strlen()
#include <assert.h>		// assert()
#include <ctype.h>		// digit()

#define FALSE 0
#define TRUE 1
#define BOOL int

BOOL IsValidIpAddress(const char *ip) //不能修改ip指向字符串的内容
{
	size_t length = 0;   // 保存ip字符串的长度

	int dot = 0;		 // '.'出现的次数
	int value = -1;		// 存储以'.'分隔的每部分字符串表示的数值，初始化为-1
	int count = 0;		// 分隔的每部分字符串的长度
	char last_ch = '\0';	// 遍历ip字符串时，上一次遍历过的字符

	assert(NULL != ip);  //断言ip不能为空

	if (12 + 3 < (length = strlen(ip)))     //ip字符串的长度不能超过12+3=15
		return FALSE;

	//开始遍历ip字符串
	while (*ip)
	{
		if (isdigit(*ip))
		{
			if (last_ch == '0')  //不能以'0'开头表示数字
				return FALSE;

			count++;
			if (count <= 3)    //最多有3个连续的数字字符
			{
				if (count == 1)		//判断是否是当前部分的第一个数字字符
					value = *ip - '0';
				else
					value = value * 10 + *ip - '0';
			}
			else
				return FALSE;
		}
		else if (*ip == '.')
		{
			if (!isdigit(last_ch)) //判断'.'之前是不是数字字符，主要防止第一个字符就是'.'
				return FALSE;
			if (dot++ > 3)			 //'.'的个数大于3，不合理
				return FALSE;

			if (0 > value || 255 < value) //判断'.'之前的整数value是否查出范围
				return FALSE;
			else
			{
				value = 0;   //未超出范围，重置value
				count = 0;
			}
		}
		else
			return FALSE;

		last_ch = *ip;   //更新上一个字符
		ip++;		//继续往后遍历
	}

	if (dot == 3 && 0 <= value && 255 >= value)  //去掉提前遇见'\0'，或者最后一个整数值过大的情况
		return	TRUE;
	else
		return FALSE;
}

void Test()
{
	char *ip[20] = { NULL };
	int i = 0;

	ip[0] = "1.1.1.1.1.1";
	ip[1] = "0.0.0.0.3";
	ip[2] = ".1.1.1";
	ip[3] = "1431.1.1.1";
	ip[4] = "441.1.1.1";
	ip[5] = "1.1.1.1e";
	ip[6] = "e1.1.g1.1";
	ip[7] = "221.122.01.1";
	ip[8] = "1...1.1.1";
	ip[9] = "1111.2221.31.1";
	ip[10] = "1.1.\01.1";
	ip[11] = "543.1.1.1";
	ip[12] = "221\0.221.221.221";
	ip[13] = "0001.1.1.";
	ip[14] = "\01.1.1.1";
	ip[15] = "1\0.1.1.1";
	ip[16] = "0.0.0.0";
	ip[17] = "127.0.0.1";
	ip[18] = "221.31.41.16";
	ip[19] = "192.168.0.134";

	for (i = 0; i < 20; i++)
	{
		printf("id %d %s is a valid ip address?", i + 1, ip[i]);

		if (IsValidIpAddress(ip[i]))
			printf("    ----> yse. \n");
		else
			printf("    ----> no \n");
	}
}

int main()
{
	Test();

	system("pause");

	return 0;
}

#endif