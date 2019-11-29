#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		for (int i = 0; i < n; i++)	{
			cin >> v[i];
		}
		if (v.size() == 0){
			cout << -1; break;
		}
		sort(v.begin(), v.end());
		int cur = v[0];
		for (auto& e : v)
		{
			if (e != cur)
			{
				cout << cur << endl;
				break;
			}
			cur++;
		}
	}
	system("pause");
	return 0;
}

//int MinEngery(vector<int>& v, int n, int x, int y)
//{
//	int engery = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int end = i;
//		if (v[i] == 0)
//		{
//			while (end < n && v[end] == 0)
//			{
//				end++;
//			}
//			engery += min(x, y);
//		}
//		i = end;
//	}
//	return engery;
//}
//
//int main()
//{
//	int n, x, y;
//	cin >> n >> x >> y;
//	vector<int> v(n, 0);
//	for (int i = 0; i < n; i++)
//		cin >> v[i];
//	int ret = MinEngery(v, n, x, y);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}