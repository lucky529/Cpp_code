#include<iostream>
#include<windows.h>
using namespace std;

//class person
//{
//protected:
//	int name = 2222;
//	int age = 18;
//};
//class student:public person
//{
//public:
//	void fun()
//	{
//		cout << name << endl;
//		cout << person::name << endl;
//	}
//protected:
//	int name = 1111;
//};
//int main()
//{
//	student s;
//	s.fun();
//
//	system("pause");
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name = "lcx")
//		: _name(name)
//	{}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{}
//
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ÐÕÃû
//};
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		: Person(name)
//		, _num(num)
//	{}
//
//	Student(const Student& s)
//		: Person(s)
//		, _num(s._num)
//	{}
//
//	Student& operator = (const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator =(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//
//	~Student()
//	{		
//		cout << "~Student()" << endl;
//		Person::~Person();
//	}
//protected:
//	int _num; //Ñ§ºÅ
//};
//void Test()
//{
//	Student s1("lcx", 18);	
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}
//
//class A
//{
//	friend void fun();
//};
//
//class B:public A
//{
//
//};
//
//void fun()
//{}


//class A
//{
//public:
//	int a;
//};
//class B : virtual public A
//{
//public:
//	int b;
//};
//class C : virtual public A
//{
//public:
//	int c;
//};
//class D : public B, public C
//{
//public:
//	int d;
//};//int main()//{//	D dd;	//	dd.B::a = 1;//	dd.C::a = 2;//	dd.b = 3;//	dd.c = 4;//	dd.d = 5;////	system("pause");//	return 0;//}class head{private:	int finger;};class preson{private:	head _h;};class preson{public:	int name;};class student:public preson{private:	int age;};