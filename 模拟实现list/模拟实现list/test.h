#pragma once
#include<iostream>
#include<windows.h>
#include<assert.h>
using namespace std;

template<class T>
struct __ListNode
{
	T _data;
	__ListNode<T>* _next;
	__ListNode<T>* _prev;

	__ListNode(const T& x = T())
		:_data(x)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

template<class T, class Ref, class Ptr>
struct __ListIterator
{
	typedef __ListNode<T> Node;
	typedef __ListIterator<T, Ref, Ptr> self;
	Node* _node;

	__ListIterator(Node* node)
		:_node(node)//Ç³¿½±´
	{}

	T& operator*()
	{
		return _node->_data;
	}

	self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	self& operator--(int)
	{
		self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	self operator++(int)
	{
		self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	T* operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const self& s)
	{
		return _node != s._node;
	}
};

template<class T>
class List
{
	typedef __ListNode<T> Node;
public:
	typedef __ListIterator<T, T&, T*> iterator;
	typedef __ListIterator<T, const T&, const T*> const_iterator;

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}

	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	List(const List<T>& l)
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

		const_iterator it = l.begin();
		while (it != l.end())
		{
			this->PushBack(*it);
			it++;
		}
	}

	List<T>& operator=(List<T> l)
	{
		Swap(l);
		return *this;
	}

	void Swap(List<T> l)
	{
		swap(_head, l._head);
	}

	void PushBack(const T& x)
	{
		/*Node* newnode = new Node(x);
		Node* tail = _head->_prev;

		tail->_next = newnode;
		newnode->_next = _head;
		newnode->_prev = tail;
		_head->_prev = newnode;*/
		Insert(begin(), x);
	}

	void Insert(iterator pos, const T& x)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* newnode = new Node(x);

		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
	}

	void PushFront(const T& x)
	{
		Insert(end(), x);
	}

	void Erase(iterator pos)
	{
		Node* cur = pos._node;
		Node* next = cur->_next;
		Node* prev = cur->_prev;

		prev->_next = next;
		next->_prev = prev;
		delete cur;
	}

	void PopBack()
	{
		Erase(--end());
	}

	void PopFront()
	{
		Erase(begin());
	}

	~List()
	{
		Clear();
		delete _head;
		_head = nullptr;
	}

	void Clear()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* next = cur->_next;
			delete cur;

			cur = next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}
private:
	Node* _head;
};

void test1()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);

	/*l.PushFront(0);
	l.PushBack(-1);*/
	l.PopBack();
	l.PopFront();
	/*auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	*/

	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	List<int> copy(l);
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	List<int> cop;
	cop = copy;
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}