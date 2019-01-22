#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<iostream>
#include<windows.h>
#include<assert.h>
using namespace std;

namespace lcx
{
	class String
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		String(char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		String(const String& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s._str);
			this->Swap(tmp);
		}

		String& operator=(String s)
		{
			Swap(s);
			return *this;
		}

		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		char* c_str()
		{
			return _str;
		}

		size_t size()
		{
			return _size;
		}

		size_t capacity()
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		bool operator<(const String& s)
		{
			int ret = strcmp(this->_str,s._str);
			if (ret < 0)			
				return true;			
			else			
				return false;			
		}

		bool operator>(const String& s)
		{
			return !((*this < s) || (*this == s));
		}

		bool operator<=(const String& s)
		{
			return !(*this > s);
		}

		bool operator>=(const String& s)
		{
			return !(*this < s);
		}

		bool operator==(const String& s)
		{
			int ret = strcmp(this->_str, s._str);
			if (ret == 0)			
				return true;			
			else			
				return false;			
		}

		bool operator!=(const String& s)
		{
			return !(*this == s);
		}

		void Reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];				
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void PushBack(char ch)
		{
			if (_size == _capacity)
			{
				Reserve(_size*2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void Append(const char* str)
		{
			if (strlen(str) + _size > _capacity)
			{
				Reserve(strlen(str) + _size);
			}
			strcpy(_str + _size, str);
			_size += strlen(str);
		}

		String& operator+=(char ch)
		{
			PushBack(ch);
			return *this;
		}

		String& operator+=(const char* str)
		{
			Append(str);
			return *this;
		}

		void Insert(size_t pos, char ch)
		{	
			assert(pos < _size);

			if (_size == _capacity)
			{
				Reserve(_size * 2);
			}			
			for (int i = _size - 1; i >= (int)pos; i--)//将pos-1位之后的数据全部挪走
			{
				_str[i+1] = _str[i];
			}
			_str[pos] = ch;//将ch插入pos位

			_str[_size + 1] = '\0';
		}

		void Insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			if (strlen(str) + _size > _capacity)
			{
				Reserve(strlen(str) + _size);
			}
			int gap = strlen(str);
			for (int i = _size - 1; i >= (int)pos; i--)//将pos+1位之后gap区间的数据全部挪走
			{
				_str[i + gap] = _str[i];
			}
			for (int i = 0; *str != '\0'; i++)
			{
				_str[pos + i] = *str;
				str++;
			}	
			_str[_size + gap] = '\0';
		}

		void Erase(size_t pos, size_t len)
		{
			assert(pos < _size);
			if (len + pos + 1 >= _size)
			{
				_str[pos] = '\0';
				return;
			}
			else
			{
				for (int i = pos; i < (int)(_size - len); i++)
				{
					_str[i] = _str[i + len];
				}
				_str[_size-len] = '\0';
			}

		}

		size_t Find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			size_t index = 0;
			char* tmp = this->c_str();
			tmp += pos;
			while (*tmp != ch && *tmp != '\0')
			{
				++tmp;
				++index;
			}
			if (index == _size)
			{
				return -1;
			}
			else
			{
				return index;
			}
		}

		size_t Find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			const char* haystack = this->c_str();
			haystack += pos;

			const char* s1 = haystack;
			const char* s2 = str;
			const char* ptr = haystack;
			while (*ptr)
			{
				s1 = ptr;
				s2 = str;
				while (*s1 && *s2 && *s1 == *s2)
				{
					s1++;
					s2++;
				}
				if (*s2 == '\0')
				{
					return s1 - haystack - strlen(str);
				}
				ptr++;
			}	
			return -1;
		}

		~String()
		{
			if (_str)
			{
				delete[] _str;
				_size = 0;
				_capacity = 0;
			}
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};
	size_t String::npos = -1;
	void test1()
	{
		String s("ehllo helle");
		String s1(s);
		String s2("world");
		/*cout << s.c_str() << endl;
		cout << s1.c_str() << endl;

		s = s1 = s2;
		cout << s.c_str() << endl;

		String::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;

		for (auto e : s)
		{
			cout << e << ' ';
		}
		cout << endl;
		cout << s.size() << endl;*/

		/*s1.PushBack('c');
		s1.Append(" world");*/
		//s1 += "a";
		//s1.Insert(1, "cc");
		/*cout << s1.c_str() << endl;*/
		//s1.Erase(6,50);
		//size_t ret = s1.Find("sb");
		//cout << ret << endl;
		//cout << s1.c_str() << endl;
	}
}