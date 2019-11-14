#include<iostream>
#include<windows.h>
#include <memory>
#include <thread>
#include <mutex>
using namespace std;

//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout << "delete:" << _ptr << endl;
//		delete[] _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";//此处抛出异常
//	}
//	return (double)a / (double)b;
//}
//
//int main()
//{
//	try
//	{
//		int* array = new int[10];
//		SmartPtr<int> sp(array);
//
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char* str)
//	{
//		cout << str << endl;
//	}
//	catch (...)
//	{
//	}
//
//	system("pause");
//	return 0;
//}

 /*1.RAII
 2.像指针一样的行为
 3.拷贝问题*/
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete[] _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

struct AA
{
	int _a1;
	int _a2;
};

int main()
{
	int* p = new int(1);
	SmartPtr<int> sp(new int(10));
	SmartPtr<int> copy(sp);

	/**p = 2;
	*sp = 20;
	sp.operator*() = 20;
	cout << *sp << endl;

	SmartPtr<AA> spaa(new AA);
	(*spaa)._a1 = 10;
	spaa->_a2 = 20;

	spaa.operator->()->_a1 = 100;

	cout << spaa->_a1 << endl;
	cout << spaa->_a2 << endl;*/

	return 0;
}
//
//
// 1.C++98 auto_ptr 管理权转移，设计缺陷，严禁使用
// 2.C++11 unique_ptr 防拷贝，简单粗暴的设计，鼓励使用
// 3.C++11 shared_ptr 引用计数，支持拷贝，鼓励使用
//
//void test_auto_ptr()
//{
//	auto_ptr<int> ap(new int);
//	*ap = 10;
//	cout << *ap << endl;
//
//	auto_ptr<int> copy(ap);
//	cout << *ap << endl;
//	cout << *copy << endl;
//}
//
//void test_unique_ptr()
//{
//	unique_ptr<int> up(new int);
//	*up = 10;
//	cout << *up << endl;
//
//	unique_ptr<int> copy(up);
//	cout << *ap << endl;
//	cout << *copy << endl;
//}
//
//void test_shared_ptr()
//{
//	shared_ptr<int> sp(new int);
//	*sp = 10;
//	cout << *sp << endl;
//
//	shared_ptr<int> copy(sp);
//	cout << *sp << endl;
//	cout << *copy << endl;
//}
//
//namespace lcx
//{
//	template<class T>
//	class AutoPtr
//	{
//	public:
//		AutoPtr(T* ptr)
//			:_ptr(ptr)
//		{}
//
//		~AutoPtr()
//		{
//			if (_ptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//
//
//		 BIT::AutoPtr<int> copy(ap);
//		AutoPtr(AutoPtr<T>& ap)
//		{
//			_ptr = ap._ptr;
//			ap._ptr = nullptr;
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//
//	template<class T>
//	class UniquePtr
//	{
//	public:
//		UniquePtr(T* ptr)
//			:_ptr(ptr)
//		{}
//
//		~UniquePtr()
//		{
//			if (_ptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		 C++11 防拷贝
//		UniquePtr(UniquePtr<T>& ap) = delete;
//	private:
//		 防拷贝 C++98 1.只声明不实现 2.私有
//		UniquePtr(UniquePtr<T>& ap);
//	private:
//		T* _ptr;
//	};
//
	template<class T>
	class SharedPtr
	{
	public:
		SharedPtr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new mutex)
		{}

		~SharedPtr()
		{
			/*if (--(*_pcount) == 0)
			{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
			delete _pcount;
			}*/

			Realase();
		}

		SharedPtr(const SharedPtr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			++(*_pcount);
			AddRefCount();
		}

		 sp1 = sp2
		SharedPtr<T>& operator=(const SharedPtr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				/*if (--(*_pcount) == 0)
				{
				delete _ptr;
				delete _pcount;
				}*/

				Realase();

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				++(*_pcount);
				AddRefCount();
			}
			return *this;
		}

		void AddRefCount()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void Realase()
		{
			bool deleteflag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0)
			{
				cout << "delete" << _ptr << endl;
				delete _pcount;
				delete _ptr;
				deleteflag = true;
			}
			_pmtx->unlock();

			if (deleteflag == true)
				delete _pmtx;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}

	private:
		T* _ptr;
		int* _pcount;
		mutex* _pmtx;
	};
}

void TestAutoPtr()
{
	lcx::AutoPtr<int> ap(new int);
	lcx::AutoPtr<int> copy(ap);
}

void TestUniquePtr()
{
	lcx::UniquePtr<int> ap(new int);
	lcx::UniquePtr<int> copy(ap);
}

void TestSharedPtr()
{
	lcx::SharedPtr<int> sp(new int);
	lcx::SharedPtr<int> copy(sp);

	lcx::SharedPtr<int> sp1(new int);
	lcx::SharedPtr<int> sp2(sp1);

	sp = sp1;
	copy = sp1;

	sp1 = sp1;
	sp1 = sp2;
}

int main()
{
	test_auto_ptr();
	test_shared_ptr();
	TestAutoPtr();
	TestUniquePtr();
	TestSharedPtr();

	return 0;
}

#include <thread>
#include <mutex>

 线程安全
mutex mtx;
void func(int* pcount, int n)
{
	for (size_t i = 0; i < n; ++i)
	{
		 不是原子操作
		mtx.lock();
		++(*pcount);
		mtx.unlock();
	}
}

int main()
{
	int count = 0, n = 1000000;
	thread t1(func, &count, n);
	thread t2(func, &count, n);

	t1.join();
	t2.join();

	cout << count << endl;
}

#include <thread>


void SharePtrFunc(BIT::SharedPtr<int>& sp, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
		lcx::SharedPtr<int> copy(sp);
	}
}

int main()
{
	lcx::SharedPtr<int> sp(new int);
	std::thread t1(SharePtrFunc, sp, 10000);
	std::thread t2(SharePtrFunc, sp, 10000);

	t1.join();
	t2.join();

	cout << sp.use_count() << endl;
}