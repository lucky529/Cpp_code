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

class NBitMap
{
public:
	NBitMap(size_t range)
	{
		_bitTable.resize((range >> 4) + 1);
	}

	void SetBit(size_t x)
	{
		size_t index = x >> 4;
		size_t num = x % 16;
		num *= 2;

		bool first = _bitTable[index] & (1 << num);
		bool second = _bitTable[index] & (1 << (num + 1));

		if (!(first && second))
		{
			_bitTable[index] += (1 << num);
		}
	}

	bool TestBit(size_t x)
	{
		size_t index = x >> 4;
		size_t num = x % 16;
		num *= 2;

		return (_bitTable[index] >> num) & 0x03;
	}

private:
	vector<int> _bitTable;
};