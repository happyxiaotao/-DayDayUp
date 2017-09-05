 0
/*
��Ŀ���ж�һ���ַ����Ƿ��ǺϷ���IP
˼·��
IP�ַ�����һ�����ʮ���ơ�
����atoi���ַ���ת��Ϊ����

����Ĳ���char *ip;
1��ipΪNULL���� ip�ĳ��ȴ���12+3=15
2�����ֳ��������ַ������ַ�֮����ַ���
3�������ַ���ʾ����������0~255֮�⡣

*/

#if 0

#include <stdio.h>  
#include <string.h>		// strlen()
#include <assert.h>		// assert()
#include <ctype.h>		// digit()

#define FALSE 0
#define TRUE 1
#define BOOL int

BOOL IsValidIpAddress(const char *ip) //�����޸�ipָ���ַ���������
{
	size_t length = 0;   // ����ip�ַ����ĳ���

	int dot = 0;		 // '.'���ֵĴ���
	int value = -1;		// �洢��'.'�ָ���ÿ�����ַ�����ʾ����ֵ����ʼ��Ϊ-1
	int count = 0;		// �ָ���ÿ�����ַ����ĳ���
	char last_ch = '\0';	// ����ip�ַ���ʱ����һ�α��������ַ�

	assert(NULL != ip);  //����ip����Ϊ��

	if (12 + 3 < (length = strlen(ip)))     //ip�ַ����ĳ��Ȳ��ܳ���12+3=15
		return FALSE;

	//��ʼ����ip�ַ���
	while (*ip)
	{
		if (isdigit(*ip))
		{
			if (last_ch == '0')  //������'0'��ͷ��ʾ����
				return FALSE;

			count++;
			if (count <= 3)    //�����3�������������ַ�
			{
				if (count == 1)		//�ж��Ƿ��ǵ�ǰ���ֵĵ�һ�������ַ�
					value = *ip - '0';
				else
					value = value * 10 + *ip - '0';
			}
			else
				return FALSE;
		}
		else if (*ip == '.')
		{
			if (!isdigit(last_ch)) //�ж�'.'֮ǰ�ǲ��������ַ�����Ҫ��ֹ��һ���ַ�����'.'
				return FALSE;
			if (dot++ > 3)			 //'.'�ĸ�������3��������
				return FALSE;

			if (0 > value || 255 < value) //�ж�'.'֮ǰ������value�Ƿ�����Χ
				return FALSE;
			else
			{
				value = 0;   //δ������Χ������value
				count = 0;
			}
		}
		else
			return FALSE;

		last_ch = *ip;   //������һ���ַ�
		ip++;		//�����������
	}

	if (dot == 3 && 0 <= value && 255 >= value)  //ȥ����ǰ����'\0'���������һ������ֵ��������
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