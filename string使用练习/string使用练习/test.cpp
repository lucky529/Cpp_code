#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

void test1()//�ַ����Ĺ���
{
	string s1;
	string s2("hello world");
	string s3(s2, 6, 3);//��ĳ���±꿪ʼ��󹹽������ַ�
	string s4(s2);//��һ��������
	string s5("hello world", 6);//ʹ���ַ�����ǰ��������
	string s6(10, 42);//42��ascll��ֵΪ*
	string s7(s2.begin() + 1, s2.begin() + 7);//ָ��һ����Χ����

	cout << s7 << endl;
}

void test2()//����=�ĸ�ֵ
{
	string s1;
	string s2("hello world");

	s1 = 'c';//����=��ֵ�ļ��ַ�ʽ
	s1 = "hello world";
	s1 = s2;

	cout << s1 << endl;
}

void test3()//����begin.end.rbegin.rend�Ȱ���ֻ�������Ӧ��
{
	//string s1("hello");
	//string::iterator it = s1.begin();//�������
	//while (it != s1.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}

	//string::reverse_iterator it = s1.rbegin();//�������
	//while (it != s1.rend())
	//{
	//	cout << *it << " ";
	//	++it;
	//}

	//const string s2("hello");
	//string::const_reverse_iterator it = s2.crbegin();//�������
	//while (it != s2.crend())
	//{
	//cout << *it << " ";
	//++it;
	//}

	//string::const_iterator it = s2.cbegin();//�������
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
	cout << s1.capacity() << endl;//����ַ����������
	s1.resize(10,'c');//û�еڶ���������ô�ַ������潫�Զ�����
	cout << s1.capacity() << endl;

	s1.reserve(50);
	cout << s1.capacity() << endl;

	s1.clear();
	//����ʱ�����Ĵ�С��һ��һ�������������������ռ���˷�
	cout << s1 << endl;

	cout << s1.empty() << endl;//����ַ�������Ϊ0����Ϊtrue������Ϊfalse��
}

void test5()//Ԫ�ط���
{
	string s1("hello");
	/*for (auto e : s1)
	{
		cout << e ;
	}
	cout<<endl;*/
	//for (int i = 0; i < s1.size(); i++)
	//{
	//	cout << s1.at(i);//������ʹ�ã���[]��������ͬ
	//}

	s1.back() = '!';//�������һ���ַ�������
	cout << s1 << endl;
}

void test6()//���η�
{
	string s1("hello");
	string s2;
	string s3("world");
	//s1.append(s1,2,10);//��2�±꿪ʼ����n���ַ�
	//s1.append("hello",5);//׷��ǰn���ַ�
	//s1.append(5,'c');//׷��n��ch

	//s1.insert(2, s3);//��posλ֮��ʼ�����ַ���
	//s1.insert(2, s3,1,10);//��ԭ�ַ���posλ����븱���ַ�����posλ��֮���n���ַ�
	//s1.insert(2, "hello",2);//��posλ֮��ʼ�����ַ���ǰn���ı�
	//s1.insert(2, 2, 'x');//��posλ֮��ʼ����n���ַ�

	//s1.erase(2);//����posλ���n��Ԫ�أ����nδ��ȷ���������֮����ַ�
	//s1.erase(s1.begin() + 1);//����ָ���ĳһ���ַ�
	//s1.erase(s1.begin());

	//s1.replace(1,3,s3);//��ԭ�ַ���1-3��λ���滻Ϊs3
	//s1.replace(s1.begin() + 1, s1.end(), s3);//����ָ�����
	//s1.replace(1,3,"world",1,5);//��ԭ�ַ���1-3��λ���滻Ϊs3��pos֮���nλ

	//swap(s1, s3);//���
	//s1.swap(s3);//ǳ����

	//cout << s1.c_str() << endl;
	
	cout << s1.find('h') << endl;
}

void test7()//�ַ�������
{
	/*string s1("string.cpp");//ȡ���ļ��ĺ�׺
	size_t pos = s1.find('.');
	string ffl(s1.substr(pos, s1.size() - pos));
	cout << ffl << endl;*/

	string url("http://www.cplusplus.com/reference/string/string/find/");//ȡ����ַ
	int start = url.find("://");
	start += 3;
	int end = url.find("/",start);//��://֮��ʼ��/

	string n(url.substr(start, end - start));
	cout << n << endl;
}
int main()
{
	test6();

	system("pause");
	return 0;
}