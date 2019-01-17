#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
using namespace std;
//
//class  B
//{
//public:
//	B(int b)//没有默认的构造函数(无参的构造函数)
//		:_b(b)
//	{
//	}
//private:
//	int _b;
//};
//class A
//{
//public:
//	A(int a, int b)
//		:d(10),
//		dday(a),
//		n(b)
//	{
//
//	}
//private:
//	const int n;
//	int& dday;
//	B d;
//};
//int main()
//{
//	system("pause");
//	return 0;
//}
//
//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(1);
//}
//
//class Array
//{
//public:
//	Array(int size = 10)
//		:_array((int*)malloc(sizeof(int)*_size))
//		, _size(size)
//	{}
//private:
//	int _size;
//	int* _array;
//};
//int main()
//{
//	Array a[10];
//	system("pause");
//	return 0;
//}
//
//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{}
//	/*explicit Date(int year)
//	:_year(year)
//	{}*/
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1 = 2019;
//	//构造一个匿名对象 拷贝构造 优化 （是一种隐式转换）
//	system("pause");
//	return 0;
//}
//
//class A
//{
//public:
//	A()
//	{
//		++rcount;
//	}
//	A(const A& d)
//	{
//		++rcount;
//	}
//	int static Get()
//	{
//		return rcount;
//	}
//private:
//	static int rcount;
//};
//int A::rcount = 0;
//int main()
//{
//	A a, b;
//	A c(a);
//
//	cout << A::Get() << endl;
//	system("pause");
//	return 0;
//}
//
//class B
//{
//public:
//	B(int b)
//		:_b(b)
//	{}
//	int _b;
//};
//class A
//{
//public:
//	void Print()
//	{
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//	}
//private:
//	// 非静态成员变量，可以在成员声明时，直接初始化。
//	int a = 10;
//	B b = 20;
//	int* p = (int*)malloc(4);
//	static int n;
//};
//int A::n = 10;
//int main()
//{
//	A a;
//	a.Print();
//
//	system("pause");
//	return 0;
//}
//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date a(2018, 3, 2);
//	a << cout;
//	return 0;
//}
//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _in, Date& d);
//public:
//	Date(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//
//	}
//	void Display()
//	{
//		cout << this->_month << this->_year << this->_day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//
//	return _cout;
//}
//istream& operator>>(istream& _in, Date& d)
//{
//	_in >> d._year;
//	_in >> d._month;
//	_in >> d._day;
//
//	return _in;
//}
//
//int main()
//{
//	Date d(2018, 3, 2);	
//	Date b();
//	cin >> d;
//	cout << d;
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;

//int main()
//{
//	int year, month, day;
//
//	while (cin >> year >> month >> day)
//	{
//		int _day = 0;
//		int arr[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//		if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//		{
//			_day = arr[month - 1] + day;
//		}
//		else
//		{
//			_day = arr[month - 1] + day + 1;
//		}
//		cout << _day << endl;
//	}
//
//	return 0;
//}
//int globalVar = 1;
//static int staticGlobalVar = 1;
//
//int main()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof (int)* 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
//	free(ptr1);
//	free(ptr3);		////	cout << sizeof(ptr1) << endl;////	system("pause");
//	return 0;
//}

//char* GetMemory(void)
//{
//   char p[] = "hello world";
//   return p;
//}
//int main()//返回局部变量或临时变量的地址
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);//	system("pause");
//	return 0;
//}

//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//int main()//将指针的地址传过去
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//
//	system("pause");
//	return 0;
//}
