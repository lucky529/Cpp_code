#pragma once
//#include"HashTable.h"
#include"common.h"


template<class K, class V, class HashFunc = HashFunc<K>>
class UnorderedMap
{
	typedef pair<K, V> ValueType;
	struct MapKeyOfValue
	{
		const K& operator()(const ValueType& v)
		{
			return v.first;
		}
	};
public:
	typedef typename HashTable<K, ValueType, MapKeyOfValue, HashFunc>::iterator iterator;

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

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = ht.Insert(make_pair(key, V()));
		return ret.first->second;
	}

private:
	HashTable<K, ValueType, MapKeyOfValue, HashFunc> ht;
};

void Maptest()
{
	UnorderedMap<int,int> mp;
	
	mp["sort"] = "≈≈–Ú";
	//mp[10] = 10;

	for (auto& e : mp)
	{
		cout << e.first << " " << e.second << endl;
	}
	cout << endl;
}