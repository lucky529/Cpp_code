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
		Node* parent = nullptr;//��¼cur�ڵ����һ���ڵ�
		Node* cur = _root;
		while (cur)
		{
			if (kov(cur->_Value) > kov(v))//�������ֵС�ڵ�ǰ�ڵ�ֵ����������
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kov(cur->_Value) < kov(v))//�������ֵ���ڵ�ǰ�ڵ�ֵ����������
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//�Ѿ����ڵ�ǰֵ
				return make_pair(iterator(cur), true);
			}
		}
		cur = new Node(v);
		cur->_col = RED;//�½ڵ�����ɫ�ڵ�
		Node* ret = cur;
		if (kov(parent->_Value) > kov(v))//��cur��������
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		while (parent && parent->_col == RED)//�����ǰ����ڵ�ĸ��׽ڵ�Ϊ��ɫ����Ҫ����
		{
			Node* grandfather = parent->_parent;//ͨ��grandfather�鿴uncle�ڵ��������һ��
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)//�������Ϊ��ɫ����Ӧ���1
				{
					uncle->_col = parent->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else//�������Ϊ��ɫ�����߲�����
				{
					if (cur == parent->_right)//�ж��Ƿ���Ҫ����˫������Ӧ���3
					{
						RotateL(parent);
						swap(cur, parent);//����ͼ���֣���Ҫ����ָ��
					}
					RotateR(grandfather);//ֻ������Ӧ�����
					parent->_col = BLACK;
					grandfather->_col = RED;
					break;
				}
			}
			else//�෴�����
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
		_root->_col = BLACK;//һ��ע�⵱���һ�����󣬿��ܸ��ڵ��Ǻ�ɫ��ÿ�β������³ɺ�ɫ
		return make_pair(iterator(ret), true);
	}

	void RotateR(Node* parent)//�ҵ���
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

	void RotateL(Node* parent)//����
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		parent->_right = SubRL;
		if (SubRL)
		{
			SubRL->_parent = parent;
		}
		SubR->_left = parent;
		Node* pNode = parent->_parent;//��¼��ǰparent�ĸ��׽ڵ㣬�Ա���SubRָ��ǰparent�ĸ��׽ڵ�
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
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };//��ͨ���
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	t.Inorder();
//	cout << "�Ǻ����" << endl;
//}