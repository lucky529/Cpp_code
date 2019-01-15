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

	int Getyearday(int year)
	{
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		{
			return 366;
		}
		else
		{
			return 365;
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
		return(_year != b._year) && (_month != b._month) && (_day != b._day);
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
		if (_year > b._year)
			return true;
		else if (_year == b._year)
		{
			if (_month == b._month)
			{
				if (_day == b._day)
					return false;
				else if (_day > b._day)
					return true;
				else
					return false;
			}
			else if (_month > b._month)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool operator>=(const Date& b)
	{
		if (_year > b._year)
			return true;
		else if (_year == b._year)
		{
			if (_month == b._month)
			{
				if (_day == b._day)
					return true;
				else if (_day > b._day)
					return true;
				else
					return false;
			}
			else if (_month > b._month)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	bool operator<=(const Date& b)
	{
		if (_year < b._year)
			return true;
		else if (_year == b._year)
		{
			if (_month == b._month)
			{
				if (_day == b._day)
					return true;
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

	Date operator+(int day)//与+=相同
	{
		_day = _day + day;		
		while (1)
		{
			if (_month > 12 || _day > Getday(_year, _month, _day))
			{
				if (_month > 12)
				{
					_month = _month - 12;
					_year = _year + 1;
				}
				if (_day > Getday(_year, _month, _day))
				{
					_day = _day - Getday(_year, _month, _day);
					_month = _month + 1;
				}
			}
			if (_year > 0 && _month > 0 && _month<13 && _day>0 && _day <= Getday(_year, _month, _day))
			{
				break;
			}
		}
		return *this;
	}

	Date operator-(int day)//与-=相同
	{
		_day = _day - day;
		while (1)
		{
			if (_month == 0 || _day <= 0)
			{
				if (_month == 0)
				{
					_month = 12;
					_year = _year - 1;
				}
				if (_day <= 0)
				{
					
					_day = _day + Getday(_year, _month - 1, _day);
					_month = _month - 1;
				}
				
			}
			if (_year > 0 && _month > 0 && _month<13 && _day>0 && _day <= Getday(_year, _month, _day))
			{
				break;
			}
		}
		return *this;
	}

	Date operator++()//前后置++相同调整++在this指针指向的_day的前后位置
	{
		++this->_day;
		while (1)
		{
			if (_month > 12 || _day > Getday(_year, _month, _day))
			{
				if (_month > 12)
				{
					_month = _month - 12;
					_year = _year + 1;
				}
				if (_day > Getday(_year, _month, _day))
				{
					_day = _day - Getday(_year, _month, _day);
					_month = _month + 1;
				}
			}
			if (_year > 0 && _month > 0 && _month<13 && _day>0 && _day <= Getday(_year, _month, _day))
			{
				break;
			}
		}
		return *this;
	}

	Date operator--()
	{
		--this->_day;
		while (1)
		{
			if (_month == 0 || _day <= 0)
			{
				if (_month == 0)
				{
					_month = 12;
					_year = _year - 1;
				}
				if (_day <= 0)
				{

					_day = _day + Getday(_year, _month - 1, _day);
					_month = _month - 1;
				}

			}
			if (_year > 0 && _month > 0 && _month<13 && _day>0 && _day <= Getday(_year, _month, _day))
			{
				break;
			}
		}
		return *this;
	}
	Date operator=(const Date& date)
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
		int tmp = b._month;
		int tmp2 = b._year;
		int tmp3 = b._day;
		while (_month != tmp)
		{
			if (_month > tmp)
			{
				_day = _day + Getday(_year, _month - 1, _day);
				_month = _month - 1;
			}
			else
			{
				tmp3 = tmp3 + Getday(b._year, b._month - 1, b._day);
				tmp = tmp - 1;
			}
		}
		while (_year != tmp2)
		{
			if (_year > tmp2)
			{
				_day = _day + Getyearday(_year - 1);
				_year = _year - 1;
			}
			else
			{
				tmp3 = tmp3 + Getyearday(b._year - 1);
				tmp2 = tmp2 - 1;
			}
		}
		if (_month == tmp && _year == tmp2)
		{
			if (_day >= tmp3)
			{
				return _day - tmp3;
			}
			else
			{
				return tmp3 - _day;
			}
		}
		else
		{
			return 0;
		}
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
	Date d1(2018, 7, 8);
	Date d2(2017, 7, 12);
	

	//d1.Display();
	cout << (d1 - d2) << endl;
	//a = b;
	//a.Display();

	system("pause");
	return 0;
}