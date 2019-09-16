#pragma once

template<class K, size_t M>
struct BtreeNode
{
	K _keys[M];
	BtreeNode<K, M>* _child[M + 1];
	BtreeNode<K, M>* _parent;
	size_t _keysize;

	BtreeNode()
	{
		for (size_t i = 0; i < M; ++i)
		{
			_keys[i] = K();
			_child[i] = nullptr;
		}
		_child[M] = nullptr;
	}
};

template<class K, size_t M>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:
	pair<Node*, int> Find(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			size_t index = 0;
			while (index < _keysize)
			{
				if (cur->_keys[index] < key)
				{
					++index;
				}
				else if (cur->_keys[index] > key)
				{
					
					break;
				}
				else
				{
					return make_pair(cur, index);
				}
			}
			parent = cur;
			cur = cur->_childs[index];
		}
		return make_pair((Node*)parent, -1);
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new BtreeNode();
			_root->_keys[0] = key;
			_root->_keysize = 1;

			return true;
		}
		pair<Node*, int> ret = Find(key);
		if (ret.second != -1)
		{
			return false;
		}

		K k = key;
		Node* cur = ret.first;
		Node* child = nullptr;
		while (1)
		{
			InsertKey(cur, k, child);
			if (cur->_keysize < M)
			{
				return true;
			}

			//节点满了。需要进行横向的分裂
			Node* newnode = new Node;
			size_t mid = M / 2;
			//[0, M/2-1] [M/2] [M/2+1, M-1]
			//拷贝数据到右区间
			size_t j = 0;
			for (size_t i = mid + 1; i < M; ++i)
			{
				newnode->_keys[j] = cur->_keys[i];
				newnode->_childs[j] = cur->_childs[i];
				if (cur->_childs[i])
				{
					cur->_childs[i]->_parent = newnode;
				}
				++j;
				newnode->_keysize++;
			}
			newnode->_childs[j] = cur->_childs[i];
			if (cur->_childs[i])
				cur->_childs[i]->_parent = newnode;

			//减去分裂走的
			cur->_keysize -= newnode->_keysize;
			//减去提取给父亲的中间数
			cur->_keysize -= 1;

			if (cur->_parent == nullptr)
			{
				_root = new Node;
				_root->_key[0] = cur->_keys[mid];
				_root->_keysize = 1;
				_root->_child[0] = cur;
				_root->_child[1] = newnode;

				return true;
			}
			else
			{
				k = cur->_keys[mid];
				cur = cur->_parent;
				child = newnode;
			}
		}
	}
private:
	Node* _root;
};