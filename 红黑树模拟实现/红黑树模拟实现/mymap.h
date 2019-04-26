#include<string>

template<class K,class V>
class MyMap
{
	typedef pair<K, V> ValueType;
public:
	struct MapKeyOfValue
	{
		const K& operator()(const ValueType& kv)
		{
			return kv.first;
		}
	};

	typedef typename RBTree<K, ValueType, MapKeyOfValue>::iterator iterator;

	pair<iterator, bool> Insert(const ValueType& key)
	{
		return t.Insert(key);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = t.Insert(make_pair(key,V()));
		return ret.first->second;
	}

	iterator begin()
	{
		return t.begin();
	}

	iterator end()
	{
		return t.end();
	}
private:
	RBTree<K, ValueType, MapKeyOfValue> t;
};

void test_mymap()
{
	MyMap<string,int> m;
	m.Insert(make_pair("123", 1));
	m.Insert(make_pair("124", 1));
	m.Insert(make_pair("125", 1));

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " ";
		++it;
	}
	cout << endl;
}