#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

template<class K, class V>
struct TreeNode
{	
	TreeNode* _left;
	TreeNode* _right;
	pair<K, V> _kv;

	TreeNode(const pair<K, V>& kv)
		: _left(nullptr)
		, _right(nullptr)
		, _kv(kv)
	{}
};

template<class K,class V>
class BSTtree
{
	typedef TreeNode<K, V> Node;
public:
	BSTtree()
		:_root(nullptr)
	{}

	BSTtree(const BSTtree<K,V>& tree)
	{
		_root = CreatTree(tree._root);
	}

	Node* CreatTree(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* newnode = new Node(root->_kv);
		newnode->_left = CreatTree(root->_left);
		newnode->_right = CreatTree(root->_right);
		return newnode;
	}

	BSTtree<K, V>& operator=(BSTtree<K, V> tree)
	{
		if (this != &tree)
		{
			swap(_root, tree._root);
		}
		return *this;
	}

	~BSTtree()
	{
		DestroyTree(_root);
		_root = nullptr;
	}

	void DestroyTree(Node* root)
	{
		if (root == nullptr)
			return;
		DestroyTree(root->_left);
		DestroyTree(root->_right);
		delete root;
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = _root;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (cur->_kv.first > parent->_kv.first)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	void InOrder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(Node* _root)
	{
		if (_root == nullptr) return;
		_Inorder(_root->_left);
		cout << _root->_kv.first << ":" << _root->_kv.second << endl;
		_Inorder(_root->_right);
	}

	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				Node* del;
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					del = cur;
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}						
					}
					del = cur;
				}
				else
				{
					Node* preplace = cur;
					Node* replace = cur->_right;
					while (replace->_left)
					{
						preplace = replace;
						replace = replace->_left;
					}
					cur->_kv.first = replace->_kv.first;
					if (preplace->_right == replace)
					{
						preplace->_right = replace->_right;
					}
					else
					{
						preplace->_left = replace->_right;
					}
					del = replace;
				}
				delete del;
				return true;
			}
		}
		return false;
	}
private:
	Node* _root;
};

void test1()
{
	BSTtree<int,string> t;
	t.Insert(make_pair(1, "0"));
	t.Insert(make_pair(2, "0"));
	t.Insert(make_pair(3, "0"));
	t.Insert(make_pair(4, "0"));
	t.Insert(make_pair(4, "0"));
	t.Insert(make_pair(5, "0"));
	t.Insert(make_pair(6, "0"));
	t.InOrder();	
	BSTtree<int, string> copy(t);
	copy.Insert(make_pair(7, "0"));
	t = copy;
	t.InOrder();
}