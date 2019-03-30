#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	FILE* fout = fopen("test.txt", "r");
	if (fout == nullptr)
	{
		cout << errno << endl;
	}

	ifstream ifs;
	ifs.open("test.txt");

	system("pause");
	return 0;
}

#include <string>

void Func2()
{
	throw 1.11111;
	throw 5;
}

void Func1()
{
	try
	{
		Func2();
	}
	catch (int i)
	{
		cout << i << endl;
	}

	FILE* fout = fopen("test.txt", "r");
	if (fout == nullptr)
	{
		string errmsg("���ļ�ʧ��");
		throw errmsg;
	}

	cout << "Func2" << endl;
}

int main()
{
	try
	{
		Func1();
	}
	catch (string& s)
	{
		cout << s << endl;
	}
	catch (int i)
	{
		cout << i << endl;
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}

	system("pause");
	return 0;
}

double Division(int a, int b) throw (const char*)
{
	 ��b == 0ʱ�׳��쳣
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}

void Func()
{
	int* array = new int[10];
	int* array2 = new int[20];
	int* array3 = new int[20];
	int* array4 = new int[20];
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete:" << array << endl;
		delete[] array;
		throw;
	}

	 ...

	delete[] array;
	cout << "delete:" << array << endl;
}

int main()
{
	try {
		Func();
	}
	catch (const char* errmsg){
		cout << errmsg << endl;
	}
	catch (...){
		cout << "unkown exception" << endl;
	}
	return 0;
}

double Division(int a, int b)
{
	 ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	 /*������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	 �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
	 �����׳�ȥ��*/
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}	
	delete[] array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	system("pause");
	return 0;
}


int main()
{
	try
	{
		string s("hello");
		cout << s.at(7) << endl;

		char* p1 = new char[0x7fffffff];
		cout << p1 << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

class BitException
{
public:
	BitException(int errid, string errmsg, string file, int line)
		:_errid(errid)
		, _errmsg(errmsg)
		, _file(file)
		, _line(line)
	{}

protected:
	int _errid;
	string _errmsg;
	string _file;
	int _line;

	//stack<string> _funcst; // ������ջ
};

double Division(int a, int b)
{
	 /*��b == 0ʱ�׳��쳣*/
	if (b == 0)
	{
		BitException e(1, "��0����", __FILE__, __LINE__);
		throw e;
	}
	return (double)a / (double)b;
}

int main()
{
	try
	{
	/*	int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;*/
		cout << string() << endl;
	}
	catch (const BitException& e)
	{
		int i = 0;
	}
	catch (...)
	{
	}
}


double Division(int a, int b)
{
	 //��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "��0����";
	}
	return (double)a / (double)b;
}