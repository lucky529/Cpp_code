#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class V>
struct HashNode
{
	V _Value;
	HashNode<V>* _next;
	HashNode(const V& v)
		:_Value(v)
		, _next(nullptr)
	{}
};

template<class K, class V, class KeyOfValue,class HashFunc>
class HashTable;

template<class K, class V, class KeyOfValue, class HashFunc>
struct HTIterator
{
	typedef HashNode<V> Node;
	typedef HTIterator<K, V, KeyOfValue, HashFunc> self;
	Node* _node;
	HashTable<K, V, KeyOfValue, HashFunc>* _ht;//需要哈希表指针来寻找迭代器下一个要到达的位置

	HTIterator(Node* node, HashTable<K, V, KeyOfValue, HashFunc>* ht)
		: _node(node)
		, _ht(ht)
	{}

	self operator++()
	{
		if (_node->_next)//直接指向下一给
		{
			_node = _node->_next;
		}
		else
		{
			//size_t index = KeyOfValue()(_node->_Value) % (_ht->_table.size());//找到当前所在表的位置
			size_t index = _ht->GetIndex(KeyOfValue()(_node->_Value), _ht->_table.size());
			++index;

			for (; index < _ht->_table.size(); index++)
			{
				if (_ht->_table[index] != nullptr)
				{
					_node = _ht->_table[index];//寻找表的下一个位置
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
		return _node->_Value;
	}

	V* operator->()
	{
		return &_node->_Value;
	}

	bool operator!=(const self& s)
	{
		return _node != s._node;
	}
};

template<class K, class V, class KeyOfValue, class HashFunc>
class HashTable
{
	typedef HashNode<V> Node;
	template<class K, class V, class KeyOfValue, class HashFunc>//模板类型的迭代器
	friend struct HTIterator;
public:
	typedef HTIterator<K, V, KeyOfValue, HashFunc> iterator;
	HashTable()
		:_size(0)
	{}

	iterator begin()
	{
		for (int i = 0; i < _table.size(); i++)
		{
			if (_table[i] != nullptr)
			{
				return iterator(_table[i], this);//this实际上就是哈希表的指针
			}
		}
		return iterator(nullptr, this);//走到这里说明此时这个哈希表为空
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	void CheckCapacity()
	{
		if (_size == _table.size())
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			vector<Node*> _newht;
			_newht.resize(newsize);
			for (int i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					//size_t index = KeyOfValue()(cur->_Value) % _newht.size();
					size_t index = GetIndex(KeyOfValue()(cur->_Value) , _newht.size());
					cur->_next = _newht[index];
					_newht[index] = cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
			_table.swap(_newht);
		}
	}	

	pair<iterator,bool> Insert(const V& v)
	{
		CheckCapacity();
		KeyOfValue kov;
		//size_t index = kov(v)%_table.size();
		size_t index = GetIndex(KeyOfValue()(v), _table.size());
		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_Value) == kov(v))//表示表中已经存在了此数据
				return make_pair(iterator(cur,this),false);
			cur = cur->_next;
		}

		Node* newnode = new Node(v);//此处进行头插，相当于对数组的赋值
		newnode->_next = _table[index];
		_table[index] = newnode;
		++_size;

		return make_pair(iterator(newnode, this), true);//注意这里构造的迭代器需要传this
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