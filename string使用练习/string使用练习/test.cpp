#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

void test1()//字符串的构造
{
	string s1;
	string s2("hello world");
	string s3(s2, 6, 3);//从某个下标开始向后构建几个字符
	string s4(s2);//用一个对象构造
	string s5("hello world", 6);//使用字符串的前六个构造
	string s6(10, 42);//42的ascll码值为*
	string s7(s2.begin() + 1, s2.begin() + 7);//指定一个范围构造

	cout << s7 << endl;
}

void test2()//重载=的赋值
{
	string s1;
	string s2("hello world");

	s1 = 'c';//重载=赋值的几种方式
	s1 = "hello world";
	s1 = s2;

	cout << s1 << endl;
}

void test3()//对于begin.end.rbegin.rend等包括只读对象的应用
{
	//string s1("hello");
	//string::iterator it = s1.begin();//正向遍历
	//while (it != s1.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}

	//string::reverse_iterator it = s1.rbegin();//逆向遍历
	//while (it != s1.rend())
	//{
	//	cout << *it << " ";
	//	++it;
	//}

	//const string s2("hello");
	//string::const_reverse_iterator it = s2.crbegin();//正向遍历
	//while (it != s2.crend())
	//{
	//cout << *it << " ";
	//++it;
	//}

	//string::const_iterator it = s2.cbegin();//正向遍历
	//while (it != s2.cend())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
}

void test4()//Capacity:
{
	string s1("hello world");
	//s1.size() == s1.length()
	s1.resize(3);
	cout << s1.capacity() << endl;//输出字符对象的容量
	s1.resize(10,'c');//没有第二个参数那么字符串后面将自动补零
	cout << s1.capacity() << endl;

	s1.reserve(50);
	cout << s1.capacity() << endl;

	s1.clear();
	//增容时容量的大小是一半一半的向上增长，来避免空间的浪费
	cout << s1 << endl;

	cout << s1.empty() << endl;//如果字符串长度为0，则为true，否则为false。
}

void test5()//元素访问
{
	string s1("hello");
	/*for (auto e : s1)
	{
		cout << e ;
	}
	cout<<endl;*/
	//for (int i = 0; i < s1.size(); i++)
	//{
	//	cout << s1.at(i);//经常不使用，与[]的意义相同
	//}

	s1.back() = '!';//返回最后一个字符的引用
	cout << s1 << endl;
}

void test6()//修饰符
{
	string s1("hello");
	string s2;
	string s3("world");
	//s1.append(s1,2,10);//从2下标开始向后的n个字符
	//s1.append("hello",5);//追加前n个字符
	//s1.append(5,'c');//追加n个ch

	//s1.insert(2, s3);//从pos位之后开始插入字符串
	//s1.insert(2, s3,1,10);//从原字符的pos位后插入副本字符串的pos位的之后的n个字符
	//s1.insert(2, "hello",2);//从pos位之后开始插入字符串前n个文本
	//s1.insert(2, 2, 'x');//从pos位之后开始插入n个字符

	//s1.erase(2);//擦除pos位后的n个元素，如果n未明确则擦除所有之后的字符
	//s1.erase(s1.begin() + 1);//擦除指向的某一个字符
	//s1.erase(s1.begin());

	//s1.replace(1,3,s3);//把原字符串1-3的位置替换为s3
	//s1.replace(s1.begin() + 1, s1.end(), s3);//利用指针代替
	//s1.replace(1,3,"world",1,5);//把原字符串1-3的位置替换为s3的pos之后的n位

	swap(s1, s3);//深拷贝
	s1.swap(s3);//浅拷贝

	cout << s1.c_str() << endl;
}

void test7()//字符串操作
{
	/*string s1("string.cpp");//取出文件的后缀
	size_t pos = s1.find('.');
	string ffl(s1.substr(pos, s1.size() - pos));
	cout << ffl << endl;*/

	string url("http://www.cplusplus.com/reference/string/string/find/");//取出网址
	int start = url.find("://");
	start += 3;
	int end = url.find("/",start);//从://之后开始找/

	string n(url.substr(start, end - start));
	cout << n << endl;
}
int main()
{
	test7();

	system("pause");
	return 0;
}