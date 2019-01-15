#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
using namespace std;
//
//class Date
	//{
	//public:
	//	void PrintA()
	//	{
	//		cout << _a << endl;
	//	}
	//
	//	void Show()
	//	{
	//		cout << "show()" << endl;
	//	}
	//private:
	//	int _a;
	//};
	//int main()
	//{
	//	Date* p = NULL;
	//	p->PrintA();//对this指针进行了解引用	
	//	p->Show();//未对this指针进行解引用
	//
	//	system("pause");
	//	return 0;
	//}

//class time
//{
//public:
//	void _print()
//	{
//		cout << "time()" << endl;
//	}
//};
//class Date
//{


//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~string()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//
//class Preson
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Preson p;	
//	system("pause");
//	return 0;
//}
class Date
{
public:		
	Date(int year = 2019,int month = 1,int day = 1)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	bool operator==(const Date& b)
	{
		return _day == b._day
			&& _month == b._month
			&& _year == b._year;
	}
	void Display()
	{
		cout << this->_year << "-"<<this->_month <<"-"<< this->_day << endl;
	}
private:
	int _year;
	int _month;
	int _day;	
};

int main()
{
	Date a(2016, 2, 3);
	Date b(2017, 2, 4);
	cout << (b == a) << endl;

	system("pause");
	return 0;
}