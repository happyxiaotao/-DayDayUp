//#include <iostream>
//using namespace std;
//
//void Sort(int *arr, int size)
//{
//	for (int i = 1; i < size; i++)
//	{
//		int key = arr[i];
//		int end = i - 1;
//
//		while (end >= 0 && arr[end] > key)
//		{
//			arr[end + 1] = arr[end];
//			end--;
//		}
//
//		arr[end + 1] = key;
//	}
//}
//
//int MinCoins(int *arr, int size, int money)
//{
//	int count = 0;
//
//	Sort(arr, size);
//
//	for (int i = 0; i < size; i++)
//	{
//		if (money >= arr[i])
//		{
//			money -= arr[i];
//			count++;
//		//	count += money / arr[i];
//		//	money %= arr[i];
//		}
//
//		if (!money)
//			break;
//	}
//
//	return money ? -1 : count;
//}
//
///*
//void Test()
//{	
//	int arr[] = { 5,2,5,3 };
//	int size = sizeof(arr)/sizeof(arr[0]);
//	int money = 15;
//
//	int count = MinCoins(arr, size, money);
//
//	cout << "count = " << count << endl;
//}
//*/