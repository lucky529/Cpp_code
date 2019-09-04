#pragma once
template<class K>
struct HashFunc
{
	const K& operator()(const K& key)
	{
		return key;
	}
};

template<>
struct HashFunc<std::string>
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