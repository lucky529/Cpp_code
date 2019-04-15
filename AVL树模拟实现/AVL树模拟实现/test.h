#include<iostream>
#include<windows.h>
#include<assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	~AVLTree()
	{
		DestoryTree(_root);
		_root = nullptr;
	}

	void DestoryTree(Node* root)//������
	{
		if (root == nullptr)
			return;
		DestoryTree(root->_left);
		DestoryTree(root->_right);
		delete root;
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;//������Ҫ����ڵ����һ���ڵ�
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)//��������ֵ�ȵ�ǰ�ڵ��ֵС������������
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)//��������ֵ�ȵ�ǰ�ڵ��ֵ�󣬾���������
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;//˵���ڵ��Ѿ�����
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)//�жϵ�ǰcur�ڵ�Ӧ��������һ���ڵ���ı�
		{
			parent->_right = cur;
			cur->_parent = parent;//��������������һ��Ҫ������
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		while (parent)//��parentΪnullptrʱ���ٸ���
		{
			if (cur == parent->_right)//����ƽ������
				parent->_bf++;
			else
				parent->_bf--;

			if (parent->_bf == 0)//������򣬽���
			{
				break;
			}
			else if (abs(parent->_bf) == 1)//�߶ȱ��ˣ���������
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)//�����������Ҫ��ת
			{
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)//���� \ ״
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)//���� > ״
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)//���� / ״
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)//���� < ״
					{
						RotateLR(parent);
					}
				}
				//��ת���,����Ӱ����һ��
				break;
			}
			else
			{
				//�����������˵��ƽ�����Ӵ���
				assert(false);
			}
		}
		return true;
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
		parent->_bf = SubL->_bf = 0;
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
		parent->_bf = SubR->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int bf = SubLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 1)
		{
			SubL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			SubL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 0)
		{
			parent->_bf = SubL->_bf = 0;
		}
		SubLR->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		int bf = SubRL->_bf;//��¼����˫��֮ǰSubRL��ƽ������

		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 1)
		{
			SubR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			SubR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf == 0)//˵�����Լ����Ǹող���Ľڵ�
		{
			parent->_bf = SubR->_bf = 0;
		}
		SubRL->_bf = 0;
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

	bool IsBlanace()//�ж����Ƿ�Ϊƽ����
	{
		return _IsBlanace(_root);
	}

	bool _IsBlanace(Node* root)
	{
		if (root == nullptr)
			return true;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return abs(leftHeight - rightHeight) < 2 && _IsBlanace(root->_left) && _IsBlanace(root->_right);
	}

	int _Height(Node* root)//�����ĸ߶�
	{
		if (root == nullptr)
			return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return rightHeight > leftHeight ? rightHeight + 1 : leftHeight + 1;
	}
private:
	Node* _root;
};

void test()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };//��ͨ���
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	int a1[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };//����������ᷢ��������
	for (auto e : a1)
	{
		t.Insert(make_pair(e, e));
	}
	t.Inorder();
	cout << t.IsBlanace() << endl;
}