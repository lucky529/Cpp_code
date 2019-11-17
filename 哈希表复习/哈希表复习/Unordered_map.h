#pragma once
#include"Common.h"
#include"HashTable.h"

template<class K, class V, class HashFunc = HashFunc<K>>
class Unordered_Map
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
	HashTable<K, V, MapKeyOfValue, HashFunc> ht;
};