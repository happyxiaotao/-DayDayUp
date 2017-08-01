#pragma once
/*
一，大整数存储
如果大整数可以被INT64存储，则存放到INT64中，同时string也维护一份。
否则，只能存储到string中。

可能传入的参数：

"        abd2341234" 
" abt34123412"
"12341234"  "+12341234"  "-12512343"
"+234afdsg" 

二，大整数加法


三，大整数减法


四，大整数乘法


五，大整数除法

*/


#include <iostream>
#include <string>
using namespace std;


typedef long long INT64;//定义long long 为INT64
const INT64 MAX_INT64 = 0x7fffffff;//定义有符号INT64的最大值
const INT64 MIN_INT64 = INT64_MAX + 1;//定义有符号INT64的最小值

//为了方便字符串之间的运算。将存储的字符串格式统一标准化为("+/-"+"数字部分")。
class BigNum
{
public:
	BigNum(INT64 data = 0)
		: _data(data)
		, _strData("0")
	{}
	BigNum(const string& strData) //不能直接将strData赋给_strData，因为可能格式不一样
	{
	}
	
	BigNum(const BigNum& big)
	{}

public:
	friend ostream&  operator << (ostream out, const BigNum& big)
	{
		return out;
	}

	friend istream& operator >> (istream in, const BigNum& big)
	{
		return in;
	}

private:
	bool 

private:
	INT64 _data;  //当存储的数据INT64可以存储时，使用该变量
	string _strData; //当存储的数据范围超过INT64的能力时，使用字符串存储
};