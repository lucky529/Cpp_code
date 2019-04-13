#include<iostream>
#include<windows.h>
#include<map>
#include<string>
using namespace std;

void test1()
{
	std::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(5, 5));
	m.insert(make_pair(4, 4));
	std::map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}

void test2()
{
	std::string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
	std::map<std::string, int> countmap;
	for (const auto& e : strs)
	{
		//std::map<std::string, int>::iterator it = countmap.find(e);
		auto it = countmap.find(e);
		if (it != countmap.end())
		{
			it->second++;
		}
		else
		{
			countmap.insert(make_pair(e, 1));
		}
	}

	//std::map<std::string, int>::iterator cit = countmap.begin();
	auto cit = countmap.begin();
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
	cout << endl;
}

void test3()
{
	std::string strs[] = { "ƻ��", "ƻ��", "����", "ƻ��", "����", "��ݮ", "��ݮ", "�㽶", "ƻ��", "ƻ��", "�㽶", "�㽶", "ƻ��", "ƻ��" };
	std::map<std::string, int> countmap;
	for (const auto& e : strs)
	{
		std::pair<std::map<std::string, int>::iterator, bool> it = countmap.insert(make_pair(e, 1));
		if (it.second == false)
		{
			it.first->second++;
		}
	}
	auto cit = countmap.begin();
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
	cout << endl;
}
int main()
{
	test3();
	system("pause");
	return 0;
}