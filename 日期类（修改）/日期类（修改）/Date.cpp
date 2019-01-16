#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
using namespace std;
class Date
{
public:
	int Getday(int year, int month, int day)
	{
		if (month == 0)
		{
			return 31;
		}
		int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else
		{
			return arr[month];
		}
	}

	Date(int year = 2019, int month = 1, int day = 1)
	{
		if (year > 0 && month > 0 && month<13 && day>0 && day <= Getday(year, month, day))
		{
			this->_year = year;
			this->_month = month;
			this->_day = day;
		}
		else
		{
			cout << "日期输入有误" << endl;
		}
	}

	bool operator==(const Date& b)
	{
		return _day == b._day
			&& _month == b._month
			&& _year == b._year;
	}

	bool operator!=(const Date& b)
	{
		return !(*this == b);
	}

	bool operator<(const Date& b)
	{
		if (_year < b._year)
			return true;
		else if (_year == b._year)
		{
			if (_month == b._month)
			{
				if (_day == b._day)
					return false;
				else if (_day > b._day)
					return false;
				else
					return true;
			}
			else if (_month > b._month)
				return false;
			else
				return true;
		}
		else
			return false;
	}

	bool operator>(const Date& b)
	{
		return !((*this == b) || (*this < b));
	}		

	bool operator>=(const Date& b)
	{
		return !(*this < b);
	}

	bool operator<=(const Date& b)
	{
		return !(*this > b);
	}

	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= (-day);
		}
		_day = _day + day;
		while (_day > Getday(_year,_month,_day))
		{			
			_day -= Getday(_year, _month, _day);
			_month += 1;
			if (_month == 13)
			{
				_year += 1;
				_month = 1;
			}
		}
		return *this;
	}

	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += (-day);
		}
		_day = _day - day;
		while (_day < 1)
		{
			_month -= 1;
			if (_month == 0)
			{
				_month = 12;
				_year -= 1;
			}
			_day += Getday(_year, _month, _day);
		}
		return *this;
	}

	Date operator-(int day)
	{
		Date ret = *this;
		return ret -= day;
	}

	Date operator+(int day)
	{
		Date ret = *this;
		return ret += day;
	}

	Date& operator++()
	{
		return *this += 1;
	}

	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}

	Date& operator--()
	{
		return *this -= 1;
	}

	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}

	Date& operator=(const Date& date)
	{
		if (this != &date)
		{
			this->_year = date._year;
			this->_month = date._month;
			this->_day = date._day;
		}
		return *this;
	}	

	int operator-(const Date& b)
	{	
		int flag = 1;
		int day = 0;
		Date max = *this;
		Date min = b;
		if (*this < b)
		{
			max = b;
			min = *this;
			flag = -1;
		}
		while (min != max)
		{
			++min;
			++day;
		}
		return day*flag;
	}

	void Display()
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2018, 7, 8);
	Date d2(2018, 7, 7);
	
	Date d1(2016, 7, 6);

	d1.operator++();
	d1.Display();
	d1.operator++(0);
	d1.Display();

	system("pause");
	return 0;
}