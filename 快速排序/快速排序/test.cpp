#include<iostream>
#include<windows.h>
using namespace std;

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//ʱ�临�Ӷ����ÿ�ζ���n�����ݣ�����logn��
//ʱ�临�Ӷ�������ֳ������ݸ߶ȴε���
//���������������õ������ѡ���key�����м�ֵ

int GetMidIndex(int* a, int start, int end)//����ȡ�л�ȡ�м����ֵ��±꣬ʵ����ʵ�ڿ�����������±꣬�Ż����ٱ���1000������������£�
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
		while (start < end && arr[end] >= arr[key])//��һ���޶�������ֹ���е�ֵ��������ѡ��keyСֱ�ӷ���Խ��
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