#include<string>
using namespace std;

template<class K>
class HashFunc
{
public:
	K& operator()(const K& key)
	{
		return key;
	}
};

template<>
class HashFunc<string>
{
	size_t operator()(const std::string& s)
	{
		size_t hash = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			hash = hash * 131 + s[i];
		}
		return hash;
	}
};