/*
题目描述：
一个数组中有一个数字的次数超过了数组的一半，求出这个字符。如：int a[]={2,3,2,2,2,2,2,5,4,1,2,3}，求出超过一半的数字是2。
*/


/*
思路：
如果，某个字符出现次数大于数组总个数的一半。
那么，该字符与其他字符，一个换一个的消除，该字符必然还有剩余。
所以：我们可以定义一个ch存储一个字符，flag表示消除过程中ch字符已知出现次数消除之后剩下的次数。
1,从头开始遍历，将遍历过程中的字符与ch比较。
2,如果相同，则flag++，否则flag--;
3,当flag为0时，表示该ch不满足遍历过程中题目要求条件。用数组下一个字符替换。
4，最终，遍历完之后，ch保存的就是满足题目要求的字符。
*/


#include <iostream>
#include <cassert>
using namespace std;

char Check_More_Than_Halt(const char *arr, size_t size)
{
	assert(arr);
	assert(size);

	int ch = arr[0];
	int flag = 1;
	int i = 1;

	for (; i < size; ++i)
	{
		if (0 == flag)  //flag为0时，需要更新ch
		{
			ch = arr[i];
			flag = 1;
		}
		else 
		{
			if (ch == arr[i]) //如果相等，则flag++;否则flag--。
				++flag;
			else
				--flag;
		}
	}
	//此时，ch必定存储出现次数大于数组个数一半的字符
	return ch;;
}

void Test()
{
	char *arr1 = "123453333333";
	char *arr2 = "5441448494247448444";

	cout << Check_More_Than_Halt(arr2, sizeof(arr2)/sizeof(arr2[0])) << endl;
}

int main()
{
	Test();

	system("pause");
	return 0;
}

