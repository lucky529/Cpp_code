//饿汉模式
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &sn;
	}
private:
	Singleton()
	{}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton sn;
};
Singleton Singleton::sn;

//懒汉模式
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (nullptr == sn)
		{
			mutx.lock();
			if (nullptr == sn)
			{
				sn = new Singleton();
			}
			mutx.unlock();
		}
		return sn;
	}
private:
	Singleton()
	{}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton* sn;
	static mutex mutx;
};
Singleton* Singleton::sn;
mutex Singleton::mutx;