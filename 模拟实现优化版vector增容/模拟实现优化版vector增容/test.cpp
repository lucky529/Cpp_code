//使用类型萃取技术，区分不需要进行深拷贝的类型
#include<iostream>
#include<string>
using namespace std;
struct FalseType
{
	bool Get()
	{
		return false;
	}
};
struct TrueType
{
	bool Get()
	{
		return true;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType IsPodType;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType IsPodType;
};
template<class T>
class Vector
{
	typedef T* iterator;
public:
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
	{}
	Vector(const Vector<T>& v)
	{
		_start = new T[v.Capacity()];
		for (int i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.Size();
		_endofstorage = _start + v.Capacity();
	}
	Vector<T>& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}
	void Swap(Vector<T>& v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_endofstorage, v._endofstorage);
	}
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	size_t Size()
	{
		return _finish - _start;
	}
	size_t Capacity()
	{
		return _endofstorage - _start;
	}
	T& operator[](size_t pos)
	{
		if (pos < Size())
			return _start[pos];
	}
	const T& operator[](size_t pos)const 
	{
		if (pos < Size())
			return _start[pos];
	}
	void PushBack(const T& x)
	{
		Insert(_finish, x);
	}
	void PopBack()
	{
		Erase(_finish - 1);
	}
	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			size_t size = Size();
			T* tmp = new T[n];
			if (size > 0)
			{
				if (TypeTraits<T>::IsPodType().Get())
				{
					memcpy(this->_start, tmp, sizeof(T)*size);
				}
				else
				{
					for (int i = 0; i < size; i++)
					{
						tmp[i] = _start[i];
					}
				}
				delete[] _start;
			}
			_start = tmp;
			_finish = _start + size;
			_endofstorage = _start + n;
		}
	}
	void Resize(size_t n, const T& x = T())
	{
		if (n > Capacity())
		{
			Reserve(n);
		}
		if (n < Size())
		{
			_finish = _start + n;
		}
		else
		{
			while (_finish < _start + n)//指针的比较
			{
				*_finish = x;
				++_finish;
			}
		}
	}
	void Insert(iterator pos, const T& x)
	{
		size_t n = pos - _start;
		if (_finish == _endofstorage)
		{
			size_t newcap = Capacity() == 0 ? 1 : Capacity() * 2;
			Reserve(newcap);
		}
		pos = _start + n;

		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end + 1) = *end;
			--end;
		}
		*pos = x;
		++_finish;
	}
	void Earse(iterator pos)
	{
		iterator cur = pos + 1;
		while (cur != _finish)
		{
			*(cur - 1) = *cur;
			++cur;
		}
		--_finish;
	}
private:
	iterator _start;
	iterator _finish;
	iterator _endofstorage;
};

int main()
{
	Vector<string> s;
	s.PushBack("hahaha");
	s.PushBack("hahaha");
	s.PushBack("hahaha");
	s.PushBack("hahaha");

	Vector<string> vv(s);
	for (auto e : s)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}