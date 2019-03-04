void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Adjustdown(int* a, int size, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (a[child] < a[child + 1] && child + 1 < size)
		{
			child = child + 1;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);

			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = ((n - 2) / 2); i >= 0; i--)
	{
		Adjustdown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		Adjustdown(a, end, 0);
		--end;
	}
}