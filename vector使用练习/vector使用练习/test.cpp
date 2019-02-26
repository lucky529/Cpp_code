#include<iostream>
#include<windows.h>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it<<' ';
		++it;
	}
	cout << endl;

	it = find(v.begin(), v.end(), 3);
	v.insert(it, 30);
	
	v.erase(it);//迭代器失效，可能是增容所导致

	//it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it << ' ';
	//	++it;
	//}
	//cout << endl;

	auto it = v.begin();
	while (it != v.end())//会跳过某些数据导致的迭代器失效
	{
		if (*it % 2 == 0)
		{
			v.erase(it);//对删除或者插入后的迭代器进行操作可能导致迭代器失效出现问题
		}
		it++;
	}

	//auto it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		it = v.erase(it);//erase会返回被删除数据的下一个迭代器
	//	}
	//	else
	//	{
	//		it++;
	//	}
	//}

	//手动释放vector的空间
	/*vector<int> v1(100, 1);
	cout << v1.capacity() << endl;
	{
		vector<int> tmp;
		tmp.swap(v1);
	}
	cout << v1.capacity() << endl;*/
	
	size_t sz;
	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';//1.5bei增容
		}
	}//gcc下二倍的增容，如果我们直到事先需要的容量我们可以调用foo.reserve来调整容量
	

	system("pause");
	return 0;
}