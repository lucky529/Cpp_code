#pragma once
#include<vector>
#include<iostream>
using namespace std;

enum State//ʹ������״̬�ֱ���� 1.�� 2.ɾ�� 3.����
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
		for (int i = 0; i < _table.size(); i++)//��hash�ڵ��ÿһ��λ�ö���ʼ��Ϊ��
		{
			_table[i]._state = EMPTY;
		}
		_size = 0;
	}

	void CheckCapacity()
	{
		if (_table.size() == 0 || (_size * 10) / _table.size() == 7)//������СΪ0���߸�������Ϊ7ʱ����
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;

			HashTable<K, V> newht(newsize);//����һ���±����±������������µĹ�������
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

		size_t index = kv.first % _table.size();//ÿ���ڵ���firstȡģ����±��������Ҫӳ���λ��
		while (_table[index]._state == EXITS)//��ǰλ����ɾ�����߿�ʱ��ʾ��ǰ��ֵ�Ϳ��Բ���
		{
			if (_table[index]._kv.first == kv.first)//�����ǰ��first����˵������ʧ��
			{
				return false;
			}

			++index;
			if (index == _table.size())//���index�Ѿ����˱�β��ô��Ҫ�ӱ�ͷ��ʼ����
			{
				index = 0;
			}
		}
		_table[index]._kv = kv;
		_table[index]._state = EXITS;
		++_size;		
		return true;
	}

	HashNode* Find(const K& key)//����һ����ڵ��ָ��
	{
		size_t index = key % _table.size();
		while (_table[index]._state != EMPTY)
		{ 
			if (_table[index]._kv.first == key && _table[index]._state == EXITS)//����ע�ⱻɾ��������Ҳ���ܱ��ҵ�
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