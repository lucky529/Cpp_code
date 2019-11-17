#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<class V>
struct HashNode
{
	V _value;
	HashNode<V>* _next;
	HashNode(const V& v)
		:_value(v)
		, _next(nullptr)
	{}
};

template<class K, class V, class KeyOfValue, class HashFunc>
class HashTable;

template<class K, class V, class KeyOfValue, class HashFunc>
struct HashTableIterator
{
	typedef HashNode<V> Node;
	typedef HashTableIterator<K, V, KeyOfValue, HashFunc> self;
	Node* _node;
	HashTable<K, V, KeyOfValue, HashFunc>* _ht;

	HashTableIterator(Node* node, HashTable<K, V, KeyOfValue, HashFunc>* ht)
		:_node(node)
		, _ht(ht)
	{}

	self operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			size_t index = _ht->GetIndex(KeyOfValue()(_node->_value), _ht->_table.size());
			++index;
			for (; index < _ht->_table.size(); index++)
			{
				if (_ht->_table[index])
				{
					_node = _ht->_table[index];
					break;
				}
			}
			if (index == _ht->_table.size())//如果已经走到结尾，那么直接将迭代器置空
			{
				_node = nullptr;
			}
		}
		return *this;
	}

	V& operator*()
	{
		return _node->_value;
	}

	V* operator->()
	{
		return &operator*();
	}

	bool operator!=(const &self s)
	{
		return _node != s._nodex;
	}
};


template<class K, class V, class KeyOfValue, class HashFunc>
class HashTable
{
	typedef HashNode<V> Node;
	template<class K, class V, class KeyOfValue, class HashFunc>
	friend struct HashTableIterator
public:
	typedef HashTableIterator<K, V, KeyOfValue, HashFunc> iterator;
	HashTable()
		:_size(0)
	{}

	pair<iterator, bool> Insert(const V& v)
	{
		CheckCapacity();
		KeyOfValue kov;
		size_t index = GetIndex(kov(v), _table.size());
		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_value) == kov(v))
			{
				return make_pair(iterator(cur, this), false);
			}
			cur = cur->_next;
		}
		Node* newnode = new HashNode(v);
		newnode->_next = _table[index];
		_table[index] = newnode;
		++_size;

		return make_pair(iterator(newnode, this), true);
	}

	void CheckCapacity()
	{
		if (_size == _table.size())
		{
			size_t newcap = _size == 0 ? 10 : _table.size() * 2;
			vector<int> _new;
			_new.resize(newcap);
			for (int i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					size_t index = GetIndex(KeyOfValue()(cur->_value), _new.size());
					cur->_next = _new[index];
					_new[index] = cur;
					cur = next;
				}
			}
			_table.swap(_new);
		}
	}
	
	size_t GetIndex(const K& key, size_t size)
	{
		HashFunc hf;
		return hf(key) % size;
	}
private:
	vector<Node*> _table;
	size_t _size;
};