#pragma once
/*
һ���������洢
������������Ա�INT64�洢�����ŵ�INT64�У�ͬʱstringҲά��һ�ݡ�
����ֻ�ܴ洢��string�С�

���ܴ���Ĳ�����

"        abd2341234" 
" abt34123412"
"12341234"  "+12341234"  "-12512343"
"+234afdsg" 

�����������ӷ�


��������������


�ģ��������˷�


�壬����������

*/


#include <iostream>
#include <string>
using namespace std;


typedef long long INT64;//����long long ΪINT64
const INT64 MAX_INT64 = 0x7fffffff;//�����з���INT64�����ֵ
const INT64 MIN_INT64 = INT64_MAX + 1;//�����з���INT64����Сֵ

//Ϊ�˷����ַ���֮������㡣���洢���ַ�����ʽͳһ��׼��Ϊ("+/-"+"���ֲ���")��
class BigNum
{
public:
	BigNum(INT64 data = 0)
		: _data(data)
		, _strData("0")
	{}
	BigNum(const string& strData) //����ֱ�ӽ�strData����_strData����Ϊ���ܸ�ʽ��һ��
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
	INT64 _data;  //���洢������INT64���Դ洢ʱ��ʹ�øñ���
	string _strData; //���洢�����ݷ�Χ����INT64������ʱ��ʹ���ַ����洢
};