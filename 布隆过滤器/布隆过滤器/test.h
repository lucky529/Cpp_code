#pragma once 
#include<vector>
using namespace std;


class BitMap
{
public:
	BitMap(size_t range)
	{
		_bitTable.resize((range >> 5) + 1);
	}

	//标识一个数字在位图中的位置
	void SetBit(size_t x)
	{
		size_t index = x >> 5;
		size_t num = x % 32;

		_bitTable[index] |= (1 << num);
	}

	//取消数字在位图当中的标识.
	void RemoveBit(size_t x)
	{
		size_t index = x >> 5;
		size_t num = x % 32;

		_bitTable[index] &= ~(1 << num);
	}


	bool TestBit(size_t x)
	{
		size_t index = x >> 5;
		size_t num = x % 32;

		return _bitTable[index] & (1 << num);
	}

private:
	vector<int> _bitTable;
};

struct HashFunc1
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (int i = 0; i < s.size(); i++)
		{
			hash = hash * 131 + s[i];
		}
		return hash;
	}
};

struct HashFunc2
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (int i = 0; i < s.size(); i++)
		{
			hash = hash * 65599 + s[i];
		}
		return hash;
	}
};

struct HashFunc3
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (int i = 0; i < s.size(); i++)
		{
			hash = hash * 1313 + s[i];
		}
		return hash;
	}
};

template<class K = string, 
class HashFunc1 = __HashFunc1<K>, 
class HashFunc2 = __HashFunc2<K>, 
class HashFunc3 = __HashFunc3<K>>

class BloomFilter
{
public:
	BloomFilter(size_t num)
		:_bm(num * 5)
		, _size(num * 5)
	{}

	void Set(const K& key)
	{
		size_t index1 = HashFunc1()(key) % _size;
		_bm.SetBit(index1);

		size_t index2 = HashFunc2()(key) % _size;
		_bm.SetBit(index2);

		size_t index3 = HashFunc3()(key) % _size;
		_bm.SetBit(index3);
	}

	bool Test(const K& key)
	{
		size_t index1 = HashFunc1()(key) % _size;
		if (_bm.TestBit(index1) == false)
		{
			return false;
		}

		size_t index2 = HashFunc2()(key) % _size;
		if (_bm.TestBit(index2) == false)
		{
			return false;
		}

		size_t index3 = HashFunc3()(key) % _size;
		if (_bm.TestBit(index3) == false)
		{
			return false;
		}
		//所有位置都为真. 但是它是不准确的.
		return true;
	}
private:
	BitMap _bm;
	size_t _size;
};