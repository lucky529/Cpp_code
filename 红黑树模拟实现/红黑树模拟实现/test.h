#include<iostream>
#include<windows.h>
using namespace std;

enum colour
{
	RED,
	BLACK
};

template<class V>
struct RBTreeNode
{
	typedef V ValueType;

	ValueType _Value;
	RBTreeNode<ValueType>* _left;
	RBTreeNode<ValueType>* _right;
	RBTreeNode<ValueType>* _parent;
	colour _col;

	RBTreeNode(const ValueType& v)
		:_Value(v)
		,_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template<class V>
struct _RBTreeiterator
{
	typedef V ValueType;
	typedef RBTreeNode<ValueType> Node;
	typedef _RBTreeiterator<ValueType> self;
public:
	Node* _node;
	_RBTreeiterator(Node* node)
		:_node(node)
	{}

	_RBTreeiterator(const self& node)
	{
		_node = node._node;
	}

	ValueType& operator*()
	{
		return _node->_Value;
	}

	ValueType* operator->()
	{
		return &_node->_Value;
	}

	self& operator=(const self& node)
	{
		_node = node._node;
	}

	bool operator!=(const self& node)
	{
		return _node != node._node;
	}

	self& operator++()
	{
		if (_node->_right == nullptr)
		{
			Node* parent = _node->_parent;
			while (parent && parent->_right == _node)
			{
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		else
		{
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}
			_node = left;
		}
		return *this;
	}
};

template<class K,class V,class KeyOfValue>
class RBTree
{
	typedef V ValueType;
	typedef RBTreeNode<ValueType> Node;
public:
	typedef _RBTreeiterator<ValueType> iterator;

	RBTree()
		:_root(nullptr)
	{}

	~RBTree()
	{}

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	pair<iterator, bool> Insert(const ValueType& v)
	{
		if (_root == nullptr)
		{
			_root = new Node(v);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		KeyOfValue kov;
		Node* parent = nullptr;//记录cur节点的上一个节点
		Node* cur = _root;
		while (cur)
		{
			if (kov(cur->_Value) > kov(v))//如果插入值小于当前节点值，向左树走
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kov(cur->_Value) < kov(v))//如果插入值大于当前节点值，向右树走
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//已经存在当前值
				return make_pair(iterator(cur), true);
			}
		}
		cur = new Node(v);
		cur->_col = RED;//新节点插入红色节点
		Node* ret = cur;
		if (kov(parent->_Value) > kov(v))//将cur插入树中
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		while (parent && parent->_col == RED)//如果当前插入节点的父亲节点为黑色则不需要调整
		{
			Node* grandfather = parent->_parent;//通过grandfather查看uncle节点在其的哪一侧
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)//如果叔叔为红色，对应情况1
				{
					uncle->_col = parent->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else//如果叔叔为黑色，或者不存在
				{
					if (cur == parent->_right)//判断是否需要进行双旋，对应情况3
					{
						RotateL(parent);
						swap(cur, parent);//对照图发现，需要交换指针
					}
					RotateR(grandfather);//只单旋对应情况二
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
			else//相反的情况
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					uncle->_col = parent->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
		}
		_root->_col = BLACK;//一定注意当情况一发生后，可能根节点是红色，每次插入后跟新成黑色
		return make_pair(iterator(ret), true);
	}

	void RotateR(Node* parent)//右单旋
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		parent->_left = SubLR;
		if (SubLR)
		{
			SubLR->_parent = parent;
		}
		SubL->_right = parent;
		Node* pNode = parent->_parent;
		parent->_parent = SubL;
		if (parent == _root)
		{
			_root = SubL;
		}
		else
		{
			if (pNode->_left == parent)
			{
				pNode->_left = SubL;
			}
			else
			{
				pNode->_right = SubL;
			}
		}
		SubL->_parent = pNode;
	}

	void RotateL(Node* parent)//左单旋
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		parent->_right = SubRL;
		if (SubRL)
		{
			SubRL->_parent = parent;
		}
		SubR->_left = parent;
		Node* pNode = parent->_parent;//记录当前parent的父亲节点，以便让SubR指向当前parent的父亲节点
		parent->_parent = SubR;
		if (_root == parent)
		{
			_root = SubR;
		}
		else
		{
			if (pNode->_left == parent)
			{
				pNode->_left = SubR;
			}
			else
			{
				pNode->_right = SubR;
			}
		}
		SubR->_parent = pNode;
	}	

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << " ";
		_Inorder(root->_right);
	}

	bool ISRBtree()
	{
		if (_root->_col == RED)
		{
			return false;
		}
		size_t n = 0;
		size_t m = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				n++;
			}
			cur = cur->_left;
		}
		return _ISRBtree(_root, m, n);
	}

	bool _ISRBtree(Node* root, size_t m, size_t n)
	{
		if (root == NULL)
		{
			if (m == n)
				return true;
			else
				return false;
		}


		if (root->_col == BLACK)
		{
			m++;
		}
		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			return false;
		}
		return _ISRBtree(root->_left, m, n) && _ISRBtree(root->_right, m, n);
	}
private:
	Node* _root;
};

//void test()
//{
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };//普通情况
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	t.Inorder();
//	cout << "是红黑树" << endl;
//}