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

	void PushBack(const T& x)
	{
		Node* newnode = new Node(x);
		Node* tail = _head->_prev;

		tail->_next = newnode;
		newnode->_next = _head;
		newnode->_prev = tail;
		_head->_prev = newnode;
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

	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}