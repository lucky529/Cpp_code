#pragma once
#include<vector>
#include<iostream>
using namespace std;

enum State//使用三种状态分别代表： 1.空 2.删除 3.存在
{
	EMPTY,
	DELETE,
	EXITS,
};

template<class K,class V>
class HashNode
{
public:
	std::pair<K, V> _kv;
	State _state;
};

template<class K,class V>
class HashTable
{
	typedef HashNode<K, V> HashNode;
public:
	HashTable(size_t N = 10)
	{
		_table.resize(N);
		for (int i = 0; i < _table.size(); i++)//将hash节点的每一个位置都初始化为空
		{
			_table[i]._state = EMPTY;
		}
		_size = 0;
	}

	void CheckCapacity()
	{
		if (_table.size() == 0 || (_size * 10) / _table.size() == 7)//如果表大小为0或者负载因子为7时增容
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;

			HashTable<K, V> newht(newsize);//创建一个新表让新表帮助我们完成新的构建操作
			for (int i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state == EXITS)
				{
					newht.Insert(_table[i]._kv);
				}
			}
			_table.swap(newht._table);
		}
	}

	bool Insert(const std::pair<K, V>& kv)
	{
		CheckCapacity();

		size_t index = kv.first % _table.size();//每个节点中first取模后的下标就是我们要映射的位置
		while (_table[index]._state == EXITS)//当前位置是删除或者空时表示当前的值就可以插入
		{
			if (_table[index]._kv.first == kv.first)//如果当前的first存在说明插入失败
			{
				return false;
			}

			++index;
			if (index == _table.size())//如果index已经到了表尾那么需要从表头开始搜索
			{
				index = 0;
			}
		}
		_table[index]._kv = kv;
		_table[index]._state = EXITS;
		++_size;		
		return true;
	}

	HashNode* Find(const K& key)//返回一个表节点的指针
	{
		size_t index = key % _table.size();
		while (_table[index]._state != EMPTY)
		{ 
			if (_table[index]._kv.first == key && _table[index]._state == EXITS)//这里注意被删除的数据也可能被找到
			{
				return &_table[index];
			}

			++index;
			if (index == _table.size())
			{
				index = 0;
			}
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		HashNode* node = Find(key);
		if (node == nullptr)
		{
			return false;
		}
		else
		{
			node->_state = DELETE;
			--_size;
		}
	}

private:
	vector<HashNode> _table;
	size_t _size;
};

void test()
{
	HashTable<int, int> ha(10);
	for (int i = 0; i < 30; i++)
	{
		ha.Insert(make_pair(i, i));
	}
	HashNode<int,int>* cur = ha.Find(20);
	ha.Erase(cur->_kv.first);
}