#include<iostream>
#include<vector>
#include<windows.h>
#include<functional>
using namespace std;


template<class T, class container = vector<T>,class cmp = less<T>>
class Pirority_queue
{
public:
	void AdJustUp(size_t child)
	{
		cmp cm;
		size_t parent = (child - 1) >> 1;
		while (child > 0)
		{
			if (cm(_con[parent], _con[child]))//注意仿函数中<或者>号的方向
			{
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
			{
				break;
			}
		}
	}

	void AdjustDown(size_t parent)
	{
		cmp cm;
		size_t child = 2 * parent + 1;
		while (child < _con.size())
		{
			if (child + 1 < _con.size() && cm(_con[child], _con[child + 1]))
			{
				++child;
			}
			if (cm(_con[parent], _con[child]))//注意仿函数中<或者>号的方向
			{
				swap(_con[child], _con[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				break;
			}
		}
	}

	void Push(const T& x)
	{
		_con.push_back(x);
		AdJustUp(_con.size() - 1);
	}

	void Pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		AdjustDown(0);
	}

	const T& Top()
	{
		return _con[0];
	}

	bool Empty()
	{
		return _con.empty();
	}

	size_t Size()
	{
		return _con.size();
	}
private:
	container _con;
};

class CmpNameLess;
class Goods
{
	friend class CmpNameLess;
public:
	Goods(int name = 10, int price = 20, int ev = 30)
	{
		_name = name;
		_price = price;
		_evaluation = ev;
	}
public:
	int _name;
	int _price;
	int _evaluation;
};

class CmpNameLess//自定义
{
public:
	bool operator()(const Goods& l, const Goods& q)
	{
		return l._name < q._name;
	}
};

void TestQueue()
{
	Pirority_queue<Goods, vector<Goods>, CmpNameLess> q;
	q.Push(Goods{ 1, 2, 3 });
	q.Push(Goods{ 2, 2, 3 });	

	while (!q.Empty())
	{
		cout << q.Top()._name <<" ";
		q.Pop();
	}
	cout << endl;
}