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

#include <iostream>
#include <cassert>
using namespace std;
void MergeSort(int* data, int left, int right)
{
	assert(data);

	if (left == right)
		return;

	int mid = left + ((right - left) >> 1);

	MergeSort(data, left, mid);
	MergeSort(data, mid + 1, right);

	int i = left;
	int j = mid + 1;

	int* temp = new int[right - left + 1];  //开辟临时数组空间
	int count = 0; //记录temp数组将要使用的位置

	while (i <= mid && j <= right)//将两个有序部分合并，存储在temp中
	{
		while (data[i] <= data[j])
		{
			temp[count] = data[i];
			count++;
			i++;
		}

		while (data[i] >= data[j])
		{
			temp[count] = data[j];
			count++;
			j++;
		}
	}

	while (count >= 0)  //将临时数组中有序数据，放入arr数组中
		data[left + count] = temp[count];
}

void Unique(int* data, int *m)
{
	assert(data && m>0);

	int i = 0;
	int offset = 1;
	while (i < *m && (i + offset)<*m)
	{
		if (data[i] == data[i + offset])
			offset++;
		else
		{
			data[i + 1] = data[i + offset];
			i++;
		}
	}
	*m = i-1;
}

int main()
{
	int n = 0;
	int m = 0;
	cin >> n;
	m = n;
	int* data = new int[n];
	int i = 0;
	for (; i < n; i++)
		cin >> data[i];
	
	int* copy = new int[n];

	for (i = 0; i < n; i++)
		cout << data[i] << " ";
	cout << endl;

	MergeSort(data, 0, n - 1);

	for (i = 0; i < n; i++)
		cout << data[i] << " ";
/*
	Unique(data, &m);

	cout << m << endl;
	for (i = 0; i < m; i++)
		cout << data[i] << " ";
*/
	delete[] data;
	delete[] copy;

	system("pause");
	return 0;
}