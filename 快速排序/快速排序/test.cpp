#include<iostream>
#include<windows.h>
using namespace std;

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//时间复杂度最好每次都排n个数据，排了logn层
//时间复杂度最坏被划分成了数据高度次的树
//有序的情况下最坏，最好的情况下选择的key都是中间值

int GetMidIndex(int* a, int start, int end)//三数取中获取中间数字的下标，实际上实在控制这颗树的下标，优化几百倍到1000倍（有序情况下）
{
	int mid = start + ((end - start) >> 1);
	if (a[start] > a[mid])
	{
		if (a[start] < a[end])
		{
			return start;
		}
		else if (a[mid] > a[end])
		{
			return mid;
		}
		else
		{
			return end;
		}
	}
	else//start < mid
	{
		if (a[start] > a[end])
		{
			return start;
		}
		else if (a[mid] < a[end])
		{
			return mid;
		}
		else
		{
			return end;
		}
	}
}
int PartSort(int* arr, int start, int end)
{
	int mid = GetMidIndex(arr, start, end);
	Swap(&arr[mid], &arr[start]);
	int key = start;
	while (start < end)
	{
		while (start < end && arr[end] >= arr[key])//第一个限定条件防止所有的值都比我们选的key小直接发生越界
		{
			end--;
		}
		while (start < end && arr[start] <= arr[key])
		{
			start++;
		}
		Swap(&arr[start], &arr[end]);
	}
	Swap(&arr[key], &arr[end]);
	return end;
}

int PartSort2(int* arr, int start, int end)
{
	//int mid = GetMidIndex(arr, start, end);
	//Swap(&arr[mid], &arr[start]);
	int key = arr[start];
	while (start < end)
	{
		while (start < end && arr[end] >= key)
		{
			--end;
		}
		arr[start] = arr[end];
		while (start < end && arr[start] <= key)
		{
			++start;
		}
		arr[end] = arr[start];
	}
	arr[start] = key;
	return start;
}

int PartSort3(int* arr, int start, int end)
{
	int key = start;
	int cur = start + 1;
	int pre = start;
	while (cur <= end)
	{
		if (arr[cur] <= arr[key] && ++pre != cur)
		{
			Swap(&arr[cur], &arr[pre]);
		}
		++cur;
	}
	Swap(&arr[key], &arr[pre]);
	return pre;
}
void QuickSort(int* arr, int start, int end)
{
	if (end <= start) return;
	int index = PartSort3(arr, start, end);
	QuickSort(arr, start, index - 1);
	QuickSort(arr, index+1, end);
}

int main()
{
	int arr[10] = { 0, 8, 7, 9, 4, 5, 6, 1, 2, 3 };
	QuickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}