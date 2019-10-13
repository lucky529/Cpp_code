//Linux��ʵ�ֵ��̳߳�
#include<iostream>
#include<pthread.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<queue>
using namespace std;

int cal(int x, int y, int op);
typedef int(*HandlerTask_t) (int x, int y, int op);
class Task{
private:
	int x;
	int y;
	int op;//0+ 1- 2* 3/
	HandlerTask_t handler;
public:
	Task(int _x = -1, int _y = -1, int _op = -1) :x(_x), y(_y), op(_op){}
	void Register(HandlerTask_t _handler)
	{
		handler = _handler;
	}
	void Run()
	{
		int ret = handler(x, y, op);
		const char* arr = "+-*/";
		cout << pthread_self() << " : " << x << arr[op] << y << "=" << ret << endl;
	}
	~Task(){}
};

class ThreadPool{
private:
	int thread_nums;//�̳߳��е��߳�����
	int idle_nums;//��ǰ�����̵߳�����
	queue<Task> task_queue;//�߳���Ҫ������������
	pthread_mutex_t lock;
	pthread_cond_t cond;
public:
	void LockQueue()
	{
		pthread_mutex_lock(&lock);
	}
	void UnlockQueue()
	{
		pthread_mutex_unlock(&lock);
	}
	bool QueueIsEmpty()
	{
		return task_queue.size() == 0 ? true : false;
	}
	void ThreadIdle()
	{
		idle_nums++;//һ������ȴ�״̬�����̼߳�һ
		pthread_cond_wait(&cond, &lock);
		idle_nums--;
	}
	void WakeupThread()
	{
		pthread_cond_signal(&cond);
	}
	void PopTask(Task& t)
	{
		t = task_queue.front();
		task_queue.pop();
	}
public:
	ThreadPool(int _num = 5) :thread_nums(_num), idle_nums(0)
	{
		pthread_mutex_init(&lock, NULL);
		pthread_cond_init(&cond, NULL);
	}
	static void* ThreadRotinue(void* arg)
	{
		pthread_detach(pthread_self());
		ThreadPool *tp = (ThreadPool*)arg;
		for (;;){
			tp->LockQueue();
			while (tp->QueueIsEmpty()){
				tp->ThreadIdle();
			}
			Task t;
			tp->PopTask(t);
			tp->UnlockQueue();
			t.Run();
		}
	}
	void InitThreadPool()//��������Ҫ���߳�
	{
		pthread_t t;
		for (auto i = 0; i < thread_nums; i++)
		{
			pthread_create(&t, NULL, ThreadRotinue, this);
		}
	}
	void PushTask(const Task& t)
	{
		LockQueue();
		task_queue.push(t);
		WakeupThread();
		UnlockQueue();
	}
	~ThreadPool()
	{
		pthread_mutex_destroy(&lock);
		pthread_cond_destroy(&cond);
	}
};

int cal(int x, int y, int op)
{
	int ret = -1;
	switch (op){
	case 0:
		ret = x + y;
		break;
	case 1:
		ret = x - y;
		break;
	case 2:
		ret = x * y;
		break;
	case 3:
		ret = x / y;
		break;
	default:
		std::cout << "cal error!" << std::endl;
	}
	return ret;
}
int main()
{
	ThreadPool tp;
	tp.InitThreadPool();
	srand((unsigned long)time(NULL));
	for (;;){
		int x = rand() % 100 + 1;
		int y = rand() % 100 + 1;
		int op = rand() % 4;
		Task t(x, y, op);
		t.Register(cal);
		tp.PushTask(t);
		sleep(1);
	}
	return 0;
}