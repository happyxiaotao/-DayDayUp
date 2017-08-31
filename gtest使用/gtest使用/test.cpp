/*
#include <iostream>
#include <tchar.h>
#include "gtest\gtest.h"
using namespace std;

inline int ADD(int i, int j)
{
	return i + j;
}
inline int SUB(int i, int j)
{
	return i - j;
}

TEST(SUB, case2)
{
	EXPECT_EQ(-1, SUB(1, 2));
	ASSERT_NE(0, SUB(1, 1));
	ASSERT_NE(0, SUB(1, 1));
	EXPECT_EQ(1, 2);
	EXPECT_LE(3, -1);
	EXPECT_GT(4, 3);
	EXPECT_GE(5, 5);
	EXPECT_NE(6, 5);
}


TEST(ADD, case1)
{
	EXPECT_TRUE(0);
	EXPECT_LT(0, -1);
	EXPECT_EQ(1, 2);
	EXPECT_LE(3, 3);
	EXPECT_GT(4, 3);
	EXPECT_GE(5, 5);
	EXPECT_NE(6, 5);
}


TEST(ADD, case2)
{
	EXPECT_TRUE(0) << " this is 0";
	EXPECT_LT(0, -1) << "0 and -1";
	EXPECT_EQ(1, 2) << "1 and 2";
	EXPECT_LE(3, 3);
	EXPECT_GT(4, 3);
	EXPECT_GE(5, 5);
	EXPECT_NE(6, 5);
}

TEST(SUB, case1)
{
	EXPECT_EQ(-1, SUB(1, 2));
	ASSERT_NE(0, SUB(1, 1));
	ASSERT_NE(0, SUB(1, 1));
	EXPECT_EQ(1, 2);
	EXPECT_LE(3, 3);
	EXPECT_GT(4, 3);
	EXPECT_GE(5, 5);
	EXPECT_NE(6, 5);
}

*/
/*
int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");

	return 0;
}
*/


#include<iostream>
#include<string>
#include "gtest\gtest.h"
using namespace std;
class Solution
{
public:
	string legalIPAddress(const string ipStr)
	{

		if (_IsIPv4(ipStr))
			return "IPv4";
		else if (_IsIPv6(ipStr))
			return "IPv6";
		else
			return "No";
	}
private:
	bool _IsIPv4(const string ipStr)
	{
		if ("" == ipStr)
			return false;
		string temp = "";
		size_t flag = 0;
		size_t count = 0;
		size_t ipLength = ipStr.length();
		for (size_t i = 0; i <= ipLength; ++i)
		{
			if ('.' != ipStr[i] && '\0' != ipStr[i])
			{
				//如果字符串中的字符包含非 . 非 数字的字符，则返回false
				if (ipStr[i]<'0' || ipStr[i]>'9')
					return false;
				temp = temp + ipStr[i];
				flag++;
				//如果数字部分超过三位数则返回false
				if (flag >= 4)
					return false;
			}
			else
			{
				//将temp转换为数字判断其范围
				if ("" != temp &&stoi(temp)<256 && stoi(temp) >= 0)
				{
					if ('0' == temp[0] && temp.length()>1)
						return false;
					count++;
					//当count=4的时候若不是最后一个字符则返回false
					if (count == 4)
						return i == ipLength;
				}
				else
					return false;
				temp = "";
				flag = 0;
			}
		}
		return false;
	}
	bool _IsIPv6(string ipStr)
	{
		if ("" == ipStr)
			return false;
		string temp = "";
		size_t flag = 0;
		size_t count = 0;
		size_t ipLength = ipStr.length();
		for (size_t i = 0; i <= ipStr.length(); i++)
		{
			if ((ipStr[i] >= '0'&&ipStr[i] <= '9') || (ipStr[i] >= 'A'&&ipStr[i] <= 'F') || (ipStr[i] >= 'a'&&ipStr[i] <= 'f'))
			{
				flag++;
				if (flag>4)
					return false;
			}
			else if (ipStr[i] == ':' || ipStr[i] == '\0')
			{
				if (flag == 0)
					return false;
				count++;
				flag = 0;
				if (8 == count)
					return i == ipLength;
			}
			else
				return false;

		}
		return false;
	}
};


TEST(Solutions,legalIPAddress)
{
	Solution s;
	string str;
	//while (cin >> str)
	//{
		const char* ret = s.legalIPAddress(str).c_str();
		//cout << s.legalIPAddress(str) << endl;
		EXPECT_STREQ("No","No");
		EXPECT_STREQ("No", "No");
		EXPECT_STREQ("No", "No");
		EXPECT_STREQ("No", "No");
		EXPECT_STREQ("No", s.legalIPAddress("1.1").c_str());
		EXPECT_STRNE("No", s.legalIPAddress("1.1.1.1").c_str());
		//EXPECT_STRNE("No", "No");
		//EXPECT_STRNE("No", "No");
//	}
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}
