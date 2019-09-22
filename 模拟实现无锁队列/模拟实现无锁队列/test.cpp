#pragma once
#include<atomic>
#include<iostream>
#include<queue>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

template<class T>
class LockFreeQueue
{
	struct Node
	{
		T _value;
		std::atomic<Node*> _next;
		Node(const T& x)
			: _value(x)
			, _next(nullptr)
		{}
	};

public:
	LockFreeQueue()
	{
		_head = _tail = new Node(T());
	}

	LockFreeQueue(const LockFreeQueue<T>&) = delete;

	~LockFreeQueue()
	{
		Node* cur = _head;
		while (cur)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
	}

	void Enqueue(const T& x)
	{
		Node* newnode = new Node(x);
		Node* oldtail = nullptr;
		Node* nullnode = nullptr;
		do
		{
			oldtail = _tail.load();
		} while (oldtail->_next.compare_exchange_weak(nullnode, newnode) != true);
		_tail.compare_exchange_weak(oldtail, newnode);
	}

	T Dequeue()
	{
		Node* oldhead = _head.load();
		T headvalue;
		do
		{
			Node* next = oldhead->_next;
			if (next == nullptr)
			{
				return T();
			}
			else
			{
				headvalue = next->_value;	
			}
		} 
		while (_head.compare_exchange_weak(oldhead, oldhead->_next) != true);

		delete oldhead;
		return headvalue;
	}

	bool Empty()
	{
		return _head.load() == _tail.load();
	}
private:
	std::atomic<Node*> _head;
	std::atomic<Node*> _tail;
};

mutex mutx;
int main()
{
	LockFreeQueue<int> lq;
	queue<int> nq;
	atomic<size_t> n = 100000;

	//测试无锁队列
	{
		size_t costtime = 0;
		vector<thread> threads;
		for (size_t i = 0; i < 3; ++i)
		{
			threads.push_back(thread([&]()
			{
				size_t begin = 0, end = 0;
				begin = clock();
				for (size_t j = 0; j < n; ++j)
				{
					lq.Enqueue(j);
				}
				end = clock();
				costtime += (end - begin);
			}));
		}
		for (auto& e : threads)
		{
			e.join();
		}
		cout << costtime << endl;
	}

	//测试有锁队列
	{
		size_t costtime = 0;
		vector<thread> threads;
		for (size_t i = 0; i < 3; ++i)
		{
			threads.push_back(thread([&]()
			{
				size_t begin = 0, end = 0;
				begin = clock();
				for (size_t j = 0; j < n; ++j)
				{
					mutx.lock();
					nq.push(j);
					mutx.unlock();
				}
				end = clock();
				costtime += (end - begin);
			}));
		}
		for (auto& e : threads)
		{
			e.join();
		}
		cout << costtime << endl;
	}


	system("pause");
	return 0;
}