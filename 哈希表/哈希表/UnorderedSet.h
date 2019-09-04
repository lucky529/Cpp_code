#pragma once
//#include"HashTable.h"
#include"common.h"

template<class K, class HashFunc = HashFunc<K>>
class UnorderedSet
{
public:
	typedef K ValueType;
	struct SetKeyOfValue
	{
		const K& operator()(const ValueType& v)
		{
			return v;
		}
	};
	typedef typename HashTable<K, ValueType, SetKeyOfValue, HashFunc>::iterator iterator;

	pair<iterator, bool> Insert(const ValueType& v)
	{
		return ht.Insert(v);
	}

	iterator begin()
	{
		return ht.begin();
	}

	iterator end()
	{
		return ht.end();
	}
private:
	HashTable<K, ValueType, SetKeyOfValue, HashFunc> ht;
};

void Settest()
{
	UnorderedSet<int> s;
	for (int i = 0; i < 20; i++)
	{
		s.Insert(i);
	}

	for (auto& e : s)
	{
		cout << e << std::endl;
	}
	int i = 0;
}
