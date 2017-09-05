#if 0

#include <iostream>

char* GetMaxSubStr(char* str, int *maxSubLen)
{
	int hash[256]; //hash��¼ÿ���ַ�������ĳ���λ��
	int strLen = 0;		//ԭ�ַ�������
	int i = 0;
	int currentStart = 0;  //��ǰ�������Ӵ��Ŀ�ͷ
	int currentLength = 0;  //��ǰ�����Ӵ��ĳ���
	int maxStart = 0;		//����Ӵ��Ŀ�ͷ
	int maxEnd = 0;		//����Ӵ��Ľ�β
	char *maxSubStart = NULL;

	memset(hash, -1, sizeof(char) * 256); //��ʼ��Ϊ-1����ʾû�б��������ַ�

	strLen = strlen(str); //����ԭ������

	for (i = 0; i<strLen; i++)	//����һ��
	{
		if (currentStart > hash[str[i]]) //���û���ظ�
		{
			hash[str[i]] = i;  //�����ַ�str[i]������ֵ�λ��
		}
		else
		{
			currentLength = i - currentStart; //��ǰ����
			if (currentLength > maxEnd - maxStart)//�����ǰ�����
			{
				maxEnd = i;
				maxStart = currentStart;
			}
			currentStart = hash[str[i]] + 1; //���µ�ǰ������
			hash[str[i]] = i; //�����ַ����ֵ�λ��
		}
	}
	if (0 == maxEnd)
	{
		*maxSubLen = maxEnd - maxStart;
		maxSubStart = str + maxStart;
	}
	else  //û���ظ����Ӵ�������ԭ��
	{
		maxSubStart = str;
		*maxSubLen = strLen;
	}

	return maxSubStart;
}

#endif