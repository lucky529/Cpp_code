#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

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
	virtual product* CreateObject() = 0;
};

class FactoryA : public Factory{
public:
	virtual product* CreateObject()
	{
		return new productA();
	}
};

class FactoryB : public Factory{
public:
	virtual product* CreateObject()
	{
		return new productB();
	}
};

int main()
{
	Factory* fya = new FactoryA();
	product* Fa = fya->CreateObject();
	Fa->show();

	Factory* fyb = new FactoryB();
	product* Fb = fyb->CreateObject();
	Fb->show();
	int a = 1;
	a = a&(-a);
	cout << a << endl;

	system("pause");
	return 0;
}