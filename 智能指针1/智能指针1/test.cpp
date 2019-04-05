#include<iostream>
#include<windows.h>
#include<memory>
#include <thread>
#include <mutex>
using namespace std;

//template<class T>
//class SmartPtr {
//public:
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//private:
//	T* _ptr;
//};
//int main()
//{
//	int* p = new int;
//	SmartPtr<int> sp(p);
//	*sp = 10;
//	cout << *sp << endl;
//	
//	system("pause");
//	return 0;
//}

//c++库中的指针指针auto_ptr使用
//int main()
//{
//	int* p = new int;
//	auto_ptr<int> ap(p);
//	auto_ptr<int> copy(ap);
//	*ap = 10;
//
//	system("pause");
//	return 0;
//}

//c++库中的指针指针auto_ptr模拟实现
template<class T>
class Auto_Ptr {
public:
	Auto_Ptr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	//Auto_Ptr(Auto_Ptr<T>& ap)
	//	:_ptr(ap._ptr)
	//{
	//	ap._ptr = nullptr;//发生拷贝构造后自己被置空
	//}

	Auto_Ptr<T>& operator=(Auto_Ptr<T>& ap)
	{
		if (this = &ap)
		{
			if (_ptr)
				delete _ptr;

			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~Auto_Ptr()
	{
		if (_ptr)
			delete _ptr;
	}
private:
	T* _ptr;
};
//int main()
//{
//	int* p = new int;
//	Auto_Ptr<int> sp(p);
//	Auto_Ptr<int> copy(sp);
//	*sp = 10;
//	cout << *sp << endl;
//	
//	system("pause");
//	return 0;
//}

//c++库中的指针指针unique_ptr模拟实现
//template<class T>
//class Unique_Ptr {
//public:
//	Unique_Ptr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//
//	Unique_Ptr(Unique_Ptr<T>& ap) = delete;
//	Unique_Ptr<T>& operator=(Unique_Ptr<T>& ap) = delete;
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	~Unique_Ptr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//private:
//	T* _ptr;
//};
//int main()
//{
//	int* p = new int;
//	Unique_Ptr<int> sp(p);
//	Unique_Ptr<int> copy(sp);
//	system("pause");
//	return 0;
//}

//c++库中的指针指针shared_ptr模拟实现
template<class T>
class Shared_Ptr {
public:
	Shared_Ptr(T* ptr = nullptr)
		: _ptr(ptr)
		, _count(new int(1))
		, _pmtx(new mutex)
	{}

	Shared_Ptr(Shared_Ptr<T>& ap)
		:_ptr(ap._ptr)
		, _count(ap._count)
		, _pmtx(ap._pmtx)
	{
		Add();
	}

	void Add()
	{
		_pmtx->lock();
		++(*_count);
		_pmtx->unlock();
	}

	void Release()
	{
		bool flag = false;
		_pmtx->lock();
		if (--(*_count) == 0)
		{
			delete _ptr;
			delete _count;
			flag = true;
		}
		_pmtx->unlock();
		if (flag == true)
			delete _pmtx;
	}

	Shared_Ptr<T>& operator=(Shared_Ptr<T>& ap)
	{
		if (_ptr != ap._ptr)
		{
			Release();
			_ptr = ap._ptr;
			_count = ap._count;
			Add();
		}
		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~Shared_Ptr()
	{
		Release();
	}
private:
	T* _ptr;
	int* _count;
	mutex* _pmtx;
};
int main()
{
	int* p = new int;
	int* pp = new int;
	Shared_Ptr<int> sp(p);
	Shared_Ptr<int> copy(sp);
	Shared_Ptr<int> sp2(pp);
	copy = sp2;

	system("pause");
	return 0;
}