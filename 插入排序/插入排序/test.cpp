#include<iostream>
#include<windows.h>
using namespace std;

//void Insert(int* arr, int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		int end = i;
//		int tmp = arr[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < arr[end])
//			{
//				arr[end + 1] = arr[end];
//				--end;
//			}
//			else
//			{
//				break;
//			}
//			arr[end + 1] = tmp;
//		}
//	}
//}
//
//void Shellsort(int* a, int n)//Ï£¶ûÅÅÐò(Ò»ÖÖÌØÊâµÄ²åÈëÅÅÐò)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//				a[end + gap] = tmp;
//			}
//		}
//	}
//}
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//void Selectsort(int* a, int n)
//{
//	int start = 0;
//	while (start < n)
//	{
//		int min = start;
//		for (int i = start; i < n; i++)
//		{
//			if (a[i] < a[min])
//			{
//				min = i;
//			}
//		}
//		Swap(&a[min], &a[start]);
//		++start;
//	}
//}

//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void Adjustdown(int* a, int size, int root)
//{
//	int parent = root;
//	int child = 2 * parent + 1;
//	while (child < size)
//	{
//		if (a[child] < a[child + 1] && child + 1 < size)
//		{
//			child = child + 1;
//		}
//		if (a[parent] < a[child])
//		{
//			Swap(&a[parent], &a[child]);
//
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//void HeapSort(int* a, int n)
//{
//	for (int i = ((n - 2) / 2); i >= 0; i--)
//	{
//		Adjustdown(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		Adjustdown(a, end, 0);
//		--end;
//	}
//}

int main()
{
	int arr[9] = { 8, 2, 1, 3, 6, 4, 7, 9, 0 };
	HeapSort(arr, 9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}