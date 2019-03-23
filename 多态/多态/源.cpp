#include<iostream>
#include<windows.h>
using namespace std;


//class person
//{
//public:
//	virtual void buy()
//	{
//		cout << "全价" << endl;
//	}
//};
//
//class student:public person
//{
//public:
//	virtual void buy()
//	{
//		cout << "半价" << endl;
//	}
//};
//
//void fun(person& p)
//{
//	p.buy();
//}
//
//int main()
//{
//	person p;
//	student s;
//	fun(p);
//	fun(s);
//
//	system("pause");
//	return 0;
//}



//class Base
//{
//public:
//	virtual void func1()
//	{}
//
//	virtual void func2()
//	{}
//
//private:
//	int a;
//};
//
//void Test1()
//{
//	Base b1;
//}
//
//int main()
//
//{
//	Test1();
//	system("pause");
//	return 0;
//}

//class Base
//{
//public:
//	virtual void func1()
//	{}
//
//	virtual void func2()
//	{}
//
//private:
//	int a;
//};
//
//class Base1:public Base
//{
//public:
//	virtual void func1()
//	{}
//
//	virtual void func3()
//	{}
//
//private:
//	int b;
//};

//typedef void(*FUNC) ();
//void PrintVT(int* table)
//{
//	cout << "虚函数表地址" << table << endl;
//	for (int i = 0; table[i] != 0; i++)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->\n", i, table[i]);
//		FUNC f = (FUNC)table[i];
//		f();
//	}
//	cout << endl;
//}

//int main()
//{
//	Base aa;
//	Base1 bb;
//	//PrintVT((int*)(*(int*)&bb));
//	system("pause");
//	return 0;
//}


//class Base1
//{
//public:
//	virtual void func1()
//	{
//		cout << "Base1::func1" << endl;
//	}
//
//	virtual void func2()
//	{
//		cout << "Base1::func2" << endl;
//	}
//
//private:
//	int b1;
//};
//
//class Base2
//{
//public:
//	virtual void func1()
//	{
//		cout << "Base2::func1" << endl;
//	}
//
//	virtual void func2()
//	{
//		cout << "Base2::func2" << endl;
//	}
//
//private:
//	int b2;
//};
//
//
//class Derive : public Base1, public Base2
//{
//public:
//	virtual void func1()
//	{
//		cout << "Derive::func1" << endl;
//	}
//
//	virtual void func3()
//	{
//		cout << "Derive::func3" << endl;
//	}
//
//private:
//	int d1;
//};
//
//typedef void(*FUNC) ();
//void PrintVTable(int* VTable)
//{
//	cout << " 虚表地址>" << VTable << endl;
//
//	for (int i = 0; VTable[i] != 0; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, VTable[i]);
//		FUNC f = (FUNC)VTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//
//void Test1()
//{
//	Derive d1;
//	//Base2虚函数表在对象Base1后面  
//	int* VTable = (int*)(*(int*)&d1);
//	PrintVTable(VTable);
//	int* VTable2 = (int *)(*((int*)&d1 + sizeof (Base1) / 4));
//	PrintVTable(VTable2);
//}
//int main()
//{
//	Test1();
//	system("pause");
//	return 0;
//}

//class person
//{
//public:
//	virtual void buy()
//	{
//		cout << "全价" << endl;
//	}
//};
//
//class student:public person
//{
//public:
//	virtual void buy()
//	{
//		cout << "半价" << endl;
//	}
//};
//
//void fun(person& p)
//{
//	p.buy();
//}
//
//int main()
//{
//	person p;
//	person* pp = &p;
//	p.buy();
//	pp->buy();
//
//	system("pause");
//	return 0;
//}

class person
{
public:
	virtual void buy() = 0;
};

class student:public person
{
public:
	virtual void buy()
	{
		cout << "半价" << endl;
	}
};