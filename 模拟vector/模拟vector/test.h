#include<iostream>
#include<windows.h>
#include<assert.h>
#include<string>
using namespace std;

namespace lcx
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		size_t Size() const
		{
			return _finish - _start;
		}

		size_t Capicaty() const
		{
			return _endofstorage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < Size())
				return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < Size());
				return _start[pos];
		}

		void Reserve(size_t n)
		{
			if (n > Capicaty())
			{
				size_t size = Size();
				T* tmp = new T[n];
				if (size > 0)
				{
					for (size_t i = 0; i < size; i++)
					{
						tmp[i] = this->_start[i];
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + size;
				_endofstorage = _start + n;
			}
		}

		void Resize(size_t n, const T& value = T())
		{
			if (n > Capicaty())
			{
				Reserve(n);
			}

			if (n < Size())
			{
				_finish = _start + n;
			}
			else
			{
				while (_finish < _start + n)
				{
					*_finish = value;
					++_finish;
				}
			}
		}

		void PushBack(const T& x)
		{
			Insert(_finish, x);
		}

		void PopBack()
		{
			Erase(_finish - 1);
		}

		void Insert(iterator pos, const T& x)
		{
			size_t n = pos - _start;
			if (_finish == _endofstorage)
			{
				size_t newcapicaty = Capicaty() == 0 ?  15 : Capicaty()*2;
				Reserve(newcapicaty);
			}
			pos = _start + n;

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			++_finish;
		}

		void Erase(iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			iterator end = pos + 1;
			while (end < _finish)
			{
				*(end - 1) = *end;
				++end;
			}
			--_finish;
		}

		Vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		Vector(const Vector<T>& v)
		{
			_start = new T[v.Size()];
			for (size_t i = 0; i < v.Size(); i++)
			{
				_start[i] = v[i];
			}
			_finish = _start + v.Size();
			_endofstorage = _start + v.Capicaty();
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

		~Vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test1()
	{
		Vector<int> v;
		v.PushBack(1);
		v.PushBack(2);
		v.PushBack(3);
		v.PushBack(4);
		/*v.PopBack();
		v.PopBack();
		v.PopBack();
		v.Resize(10, 2);*/
		Vector<int> copy;
		copy = v;

		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test2()
	{
		Vector<string> v;
		v.PushBack("1111");
		v.PushBack("1112");
		v.PushBack("1113");
		v.PushBack("1114");

		cout << v.begin() << endl;
		cout << v.begin()+1 << endl;
		cout << v.begin()+2 << endl;
		cout << v.begin()+3 << endl;
	}
}
template<class T>
class vector
{
public:
	typedef T* iterator;
private:
	iterator _start;
	iterator _finish;
	iterator _endofstorage;
};