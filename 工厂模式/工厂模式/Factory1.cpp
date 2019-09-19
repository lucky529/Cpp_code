#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

简单工厂模式，违反了开闭原则(可以扩展但是不支持修改)
enum {
	typeA,
	typeB
};

class product {
public:
	virtual void show() = 0;
};

class productA : public product{
public:
	virtual void show()
	{
		cout << "product A" << endl;
	}
};

class productB : public product{
public:
	virtual void show()
	{
		cout << "product B" << endl;
	}
};

class Factory{
public:
	static product* CreateObject(int type)
	{
		switch (type)
		{
		case typeA:
			return new productA();
		case typeB:
			return new productB();
		default:
			break;
		}
	}
};


int main()
{
	Factory* fy = new Factory();

	product* Fa = fy->CreateObject(typeA);
	Fa->show();

	product* Fb = fy->CreateObject(typeB);
	Fb->show();

	system("pause");
	return 0;
}