#include<iostream>
#include<windows.h>
#include<vector>
using namespace std;

int main()
{
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);*/

	//auto it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it<<' ';
	//	++it;
	//}
	//cout << endl;

	//it = find(v.begin(), v.end(), 3);
	//v.insert(it, 30);
	//
	//v.erase(it);//������ʧЧ������������������

	//it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it << ' ';
	//	++it;
	//}
	//cout << endl;

	//auto it = v.begin();
	//while (it != v.end())//������ĳЩ���ݵ��µĵ�����ʧЧ
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v.erase(it);//��ɾ�����߲����ĵ��������в������ܵ��µ�����ʧЧ��������
	//	}
	//	it++;
	//}

	//auto it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		it = v.erase(it);//erase�᷵�ر�ɾ�����ݵ���һ��������
	//	}
	//	else
	//	{
	//		it++;
	//	}
	//}

	//�ֶ��ͷ�vector�Ŀռ�
	/*vector<int> v1(100, 1);
	cout << v1.capacity() << endl;
	{
		vector<int> tmp;
		tmp.swap(v1);
	}
	cout << v1.capacity() << endl;*/
	
	//size_t sz;
	//std::vector<int> foo;
	//sz = foo.capacity();
	//std::cout << "making foo grow:\n";
	//for (int i = 0; i < 100; ++i) {
	//	foo.push_back(i);
	//	if (sz != foo.capacity()) {
	//		sz = foo.capacity();
	//		std::cout << "capacity changed: " << sz << '\n';//1.5bei����
	//	}
	//}//gcc�¶��������ݣ��������ֱ��������Ҫ���������ǿ��Ե���foo.reserve����������
	

	system("pause");
	return 0;
}