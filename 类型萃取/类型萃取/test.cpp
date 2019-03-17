#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

//程序奔溃，memcpy对string进行了浅拷贝，应该进行深拷贝
//template<class T>
//void Copy(T* dst, const T* src, size_t size)
//{
//	memcpy(dst, src, sizeof(T)*size);
//}
//int main()
//{
//	string strarr1[3] = { "11", "22", "33" };
//	string strarr2[3];
//	Copy(strarr2, strarr1, 3);
//}

//类型萃取
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType IsPODType;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<long>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType IsPODType;
};

//编写程序中，我们可以将不需要深拷贝的自定义类型也进行类似内置类型的处理


template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get())
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
			dst[i] = src[i];
	}
}
int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int a2[10];
	Copy(a2, a1, 10);

	string s1[] = { "1111", "2222", "3333", "4444" };
	string s2[4];
	Copy(s2, s1, 4);

	system("pause");
	return 0;
}

