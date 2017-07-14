/*
实现一个Add函数，让两个数相加，但是不能使用 + 、 - 、*、 / 等四则运算符。
ps:也不能用++、--等等
*/

#include <stdio.h>
#include <stdlib.h>


/*
思路：
1，数组通过下标的偏移，可以计算出基于首元素地址的某一元素位置，从而访问该元素。
那么我们可以利用编译器的这种行为，来让编译器自动帮我们进行加法运算。
2，32位下， int值与指针的sizeof大小都是4字节。char的大小为1字节。
所以，可以将两数a和b中。a强转为char*类型地址c。这样，b用来表示下标，计算c[b]时，是以1字节为单位计算偏移的。
*/
int Add_1(int a, int b)
{
	char *c = (char *)a; //将a表示的值，看做是地址c。并且类型要是char*。因为sizeof(char)=1

	return (int)&c[b]; //&a[b]-->a+sizeof(char)*b表示地址。(int)强转为int值
}


/*
思路：
1,0和1可以表示某一位上的数值。（对于sum来说）
2，0和1还可以表示两种状态，即序列中某一位的状态（不需要进位与需要进位）。（对于carry来说）
3，a^b运算的结果是：二进制序列，不进位，只相加的结果sum。(0^0=0,1^0=1,1^1=0)
4，a&b运算，然后左移一位，的结果是：二进制序列中哪些位是需要进位carry。（0&0=0,1&0=0,1&1=1，然后将序列左移1位）
5，通过sum与carry带入3，4中的a与b，可以从后往前不断进位，直到carry为0，表示没有需要进位的位。
*/

/*
//递归版本
int Add_2(int a, int b)
{
	if (0==b) 
		return a;
	else
	{
		int sum = a ^ b; // 各位相加，不计进位
		int carry = (a & b) << 1; // 记下进位
	    Add_2(sum, carry); // 求sum和carry的和
	}
}
*/
/**/
//迭代版本
int Add_2(int a, int b)
{
	while (b)
	{
		int sum = a ^ b;
		int carry = (a & b) << 1;

		a = sum;
		b = carry;
	}
	return a;
}




/*
思路：
1，Add函数需要返回一个值。那么在那么多限制条件下，可以利用位运算符，返回一个像样的运算结果。
2，&返回的是两个数相同的二进制位序列，值为a。^返回的是两个数不同的二进制序列，值为b。
3，2*a+b得到的就是两个数的和了。

可以利用画图，来理解。
*/
int Add_3(int n1, int n2)
{
	int a = n1 & n2;
	int b = n1 ^ n2;

	return (2 * a + b); //因为有四则运算符号，所以舍弃掉。
}

int main()
{
	int i = 0;
	int j = 0;
	int a[5] = {1,2,3,4,5};
/*	
测试b为负数的情况
	int* p = NULL;
	p = &a[3];
	printf("a[-1] = %d\n", p[-1]);
*/
/*
测试相同二进制序列的读取
	char c1 = -128;
	char c2 = 128;
	printf("c1 = %d, c2 = %d\n", c1, c2);
*/
	/*测试用例*/
	for (i = -10, j = -100; i < 20; ++i, j+=10)
	{
		int ret = i + j;
		printf("ret = %d+%d = %d, Add(%d,%d) = %d\n", i, j, i + j, i, j, Add_2(i, j));
	}
	printf("%x\n", (unsigned int )-10+10);
	printf("%d\n", 0xfffffff6+10);
	
/*
测试整型提升
	if (((unsigned int)-10 - 11) < 0)
		printf("haaaaaaaaaaaa\n");
*/
	system("pause");
	return 0;
}
