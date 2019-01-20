//#include<iostream>
//#include<windows.h>
//#include<string>
//using namespace std;
//
//template <class T>
//void Swap(T& a,T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//
// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}
//
////类模板
//template<class T>
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)
//		: _arr(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//
//	~Vector();
//
//	void PushBack(const T& data)
//	{
//		_arr[_size++] = data;
//	}
//
//	void PopBack()
//	{
//		--_size;
//	}
//
//	size_t Size()
//	{
//		return _size;
//	}
//
//	T& operator[](size_t pos)
//	{		
//		return _arr[pos];				
//	}
//private:
//	T* _arr;
//	size_t _size;
//	size_t _capacity;
//};
//
//template<class T>
//Vector<T>::~Vector()
//{
//	if (_arr)
//	{
//		delete[] _arr;
//	}
//}
//int main()
//{
//	Vector<int> s;
//	s.PushBack(1);
//	s.PushBack(1);
//	s.PushBack(1);
//	for (size_t i = 0; i < s.Size(); i++)
//	{
//		cout << s.operator[](i) << endl;
//	}	//
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	string s;
//	s += "ABSIB T";
//		int len = s.size() - 1;
//		int count = 0;
//		while (s[len] == ' ' && len >= 0)
//		{
//			len--;
//		}
//		while (s[len] != ' ' && len >= 0)
//		{
//			count++;
//			len--;
//		}
//		cout << count << endl;
//		system("pause");
//	return 0;
//}

//int main()
//{
//	string s("123");
//	string s2("12");
//	s = '0'+ s;//给字符串前加'0'
//	cout << s << endl;
//	int tmp = s[3] - '0';
//	cout << tmp << endl;
//	system("pause");
//	return 0;
//}