
template<class K>
class MySet
{
public:
	typedef K ValueType;
	struct SetKeyOfValue
	{
		const K& operator()(const ValueType& key)
		{
			return key;
		}
	};
	
	typedef typename RBTree<K, K, SetKeyOfValue>::iterator iterator;	

	pair<iterator, bool> Insert(const ValueType& key)
	{
		return t.Insert(key);
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
	RBTree<K, ValueType, SetKeyOfValue> t;
};

void test_myset()
{
	MySet<int> s;
	s.Insert(1);
	s.Insert(2);
	s.Insert(3);

	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}