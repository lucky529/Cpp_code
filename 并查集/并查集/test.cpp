#pragma once
#include<vector>
using namespace std;

class UnionSet
{
public:
	UnionSet(int size)
	{
		uset.resize(size, -1);
	}
	int FindRoot(int x)
	{
		while (uset[x] >= 0)
		{
			x = uset[x];
		}
		return x;
	}
	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if (root1 == root2)
			return false;

		uset[root1] += uset[root2];
		uset[root2] = root1;
		return true;
	}
	size_t Count()const
	{
		size_t count = 0;
		for (auto e : uset)
		{
			if (e < 0)
				++count;
		}
		return count;
	}
private:
	vector<int> uset;
};