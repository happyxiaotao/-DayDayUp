
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

/*   第一种方法， 暴力破解法
//时间复杂度：O（aim^N）
int process1(int arr[], int length, int index, int aim)
{
	int res = 0;
	if (length == index)
		res = (0 == aim ? 1 : 0);
	else
		for (int i = 0; i*arr[index] <= aim; i++)
			res += process1(arr, length, index+1, aim-i*arr[index]);
	return res;
}
int coins1(int arr[], int length, int aim)
{
	assert(NULL != arr);
	assert(0 < length);
	assert(0 <= aim);

	return process1(arr, length, 0, aim);
}
*/


/*第二种方法， 记忆搜索法， 通过添加map记录每次函数返回值
// 时间复杂度：O（N*aim^2）
int process2(int arr[], int length, int index, int aim, vector <vector<int>>& map)
{
	int res = 0;
	if (length == index)
		res = (0 == aim ? 1 : 0);
	else
	{
		int value = 0;
		for (int i = 0; i*arr[index] <= aim; i++)
		{
			value = map[index][aim];
			if (value == 0)
				res += process2(arr, length, index + 1, aim - i*arr[index], map);
			else
				res += (value == -1?0:value);
		}
	}
	map[index][aim] = res;
	return res;
}
int coins2(int arr[], int length, int aim)
{
	assert(NULL != arr);
	assert(0 < length);
	assert(0 <= aim);

	vector< vector<int>> map;
	map.resize(length+1);
	for (int i = 0; i < length + 1; i++)
		map[i].resize(aim+1);

	return process2(arr, length, 0, aim, map);
}
*/


/* 第三种方法， 动态规划，利用矩阵dp[length][aim+1] 
//时间复杂度：O（N*aim^2）
int coins3(int* arr, int length, int aim)
{
	assert(0 < length);
	assert(0 <= aim);

	vector< vector<int>> dp(length);
	for (int i = 0; i < length; i++)
		dp[i].resize(aim+1);
	int i = 0;
	int j = 0;
	int k = 0;
	for (; i < length; i++)
		dp[i][0] = 1;
	for (k = 1; k*arr[0] <= aim; k++)
		dp[0][k*arr[0]] = 1;

	for (i = 1; i < length; i++)
	{
		for (j = 1; j <= aim; j++)
		{
			int num = 0;
			for (k = 0; k*arr[i] <= j; k++)
				num += dp[i - 1][j - k*arr[i]];
			dp[i][j] = num;
		}
	}

	return dp[length-1][aim];
}
*/

/* 利用dp[i][j] = dp[i-1][j] + dp[i][j-arr[i]]，代替最内层循环
int coins4(int* arr, int length, int aim)
{
	assert(NULL != arr);
	assert(0 < length);
	assert(0 <= aim);

	int i = 0;
	int j = 0;
	vector<vector<int>> dp(length);
	for (; i < length; i++)
		dp[i].resize(aim+1);

	for (i = 0; i < length; i++)
		dp[i][0] = 1;
	for (j = 1; j*arr[0] <= aim; j++)
		dp[0][j*arr[0]] = 1;

	for (i = 1; i < length; i++)
		for (j = 1; j <= aim; j++)
		{
			dp[i][j] = dp[i - 1][j];
			dp[i][j] += (j >= arr[i] ? dp[i][j - arr[i]] : 0);
		}

	return dp[length-1][aim];
}
*/

/* 第五种方法，动态规划 + 结合空间压缩*/
int coins5(int* arr, int length, int aim)
{
	assert(NULL != arr);
	assert(0 < length);
	assert(0 <= aim);

	int i = 0;
	int j = 0;
	vector<int> dp(aim+1, 0);
	
	for (; i*arr[0] <= aim; i++)
		dp[i*arr[0]] = 1;

	for (i = 1; i < length; i++)
		for (j = 1; j <= aim; j++)
			dp[j] += (j - arr[i] >= 0 ? dp[j-arr[i]] : 0);

	return dp[aim];
}

int main()
{
	int arr[] = {5, 10, 25, 1};
	int aim = 15;
	int length = sizeof(arr)/sizeof(int);

	int sum = coins5(arr, length, aim);

	printf("sum = %d\n", sum);


	system("pause");
	return 0;
}