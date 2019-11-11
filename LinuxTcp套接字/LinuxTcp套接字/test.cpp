//多进程版本
#include<iostream>
#include<string>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<cstring>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
using namespace std;

class TcpServer{
private:
	int listen_sock;
	string ip;
	int port;
public:
	TcpServer(string _ip, int _port) :ip(_ip), port(_port), listen_sock(-1)
	{}
	void InitServer()
	{
		listen_sock = socket(AF_INET, SOCK_STREAM, 0);
		if (listen_sock < 0){
			cerr << "listen_sock error" << endl;
			exit(2);
		}
		int opt = 1;
		setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
		struct sockaddr_in local;
		bzero(&local, sizeof(local));
		local.sin_family = AF_INET;
		local.sin_port = htons(port);
		local.sin_addr.s_addr = inet_addr(ip.c_str());//INADDR_ANY
		//假设我有两张网卡也都可以通过此端口进行链接
		if (bind(listen_sock, (struct sockaddr*)&local, sizeof(local)) < 0){
			cout << "bind error " << endl;
			exit(3);
		}
		if (listen(listen_sock, 5) < 0){
			cout << "listen error" << endl;
			exit(4);
		}
		signal(SIGCHLD, SIG_IGN);
	}
	void Service(int sock)
	{
		char buf[1024];
		while (1){
			ssize_t s = read(sock, buf, sizeof(buf)-1);
			if (s > 0){
				buf[s] = 0;
				write(sock, buf, strlen(buf));
			}
			else if (s == 0){
				cout << "client quit!" << endl;
				break;
			}
			else{
				cerr << "read error" << endl;
				break;
			}
		}
		close(sock);
	}
	void Start()
	{
		struct sockaddr_in peer;
		socklen_t len;
		for (;;){
			len = sizeof(peer);
			int sock = accept(listen_sock, (struct sockaddr*)&peer, &len);
			if (sock < 0){
				cerr << "accept error" << endl;
				continue;
			}
			std::cout << " Get a new client " << sock << endl;
			pid_t id = fork();
			if (id < 0){
				cout << "fork error" << endl;
				close(sock);
			}
			else if (id == 0){
				//if(fork() > 0){
				//    exit(1);
				//}
				close(listen_sock);
				Service(sock);
				exit(0);
			}
			else{
				close(sock);
			}
		}
	}
	~TcpServer()
	{
		if (listen_sock > 0)
			close(listen_sock);
	}
};
//多线程版本
#include<iostream>
#include<string>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<cstring>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#include<pthread.h>
using namespace std;

class TcpServer;
class Arg{
public:
	string iip;
	int pport;
	int ssock;
	TcpServer* tsp;
};
class TcpServer{
private:
	int listen_sock;
	int port;
public:
	TcpServer(int _port) :port(_port), listen_sock(-1)
	{}
	void InitServer()
	{
		listen_sock = socket(AF_INET, SOCK_STREAM, 0);
		if (listen_sock < 0){
			cerr << "listen_sock error" << endl;
			exit(2);
		}
		int opt = 1;
		setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
		struct sockaddr_in local;
		bzero(&local, sizeof(local));
		local.sin_family = AF_INET;
		local.sin_port = htons(port);
		local.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY
		if (bind(listen_sock, (struct sockaddr*)&local, sizeof(local)) < 0){
			cout << "bind error " << endl;
			exit(3);
		}
		if (listen(listen_sock, 5) < 0){
			cout << "listen error" << endl;
			exit(4);
		}
		signal(SIGCHLD, SIG_IGN);
	}
	void Service(int sock, string ip, int port)
	{
		char buf[1024];
		while (1){
			ssize_t s = read(sock, buf, sizeof(buf)-1);
			if (s > 0){
				buf[s] = 0;
				cout << "[" << ip << ":" << port << "]#" << buf << endl;
				write(sock, buf, strlen(buf));
			}
			else if (s == 0){
				cout << "client quit!" << endl;
				break;
			}
			else{
				cerr << "read error" << endl;
				break;
			}
		}
		close(sock);
	}
	static void* Run(void* arg)//-> service
	{
		pthread_detach(pthread_self());
		Arg* sarg = (Arg*)arg;
		sarg->tsp->Service(sarg->ssock, sarg->iip, sarg->pport);
		delete sarg;
	}
	void Start()
	{
		struct sockaddr_in peer;
		socklen_t len;
		for (;;){
			len = sizeof(peer);
			int sock = accept(listen_sock, (struct sockaddr*)&peer, &len);
			if (sock < 0){
				cerr << "accept error" << endl;
				continue;
			}
			std::cout << " Get a new client " << sock << endl;
			int port_ = ntohs(peer.sin_port);
			string ip_ = inet_ntoa(peer.sin_addr);

			pthread_t tid;
			Arg* arg = new Arg;
			arg->iip = ip_;
			arg->ssock = sock;
			arg->pport = port_;
			arg->tsp = this;
			pthread_create(&tid, NULL, Run, (void*)arg);
		}
	}
	~TcpServer()
	{
		if (listen_sock > 0)
			close(listen_sock);
	}
};

//线程池版本

#include<iostream>
#include<string>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<cstring>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#include<pthread.h>
#include"ThreadPool.hpp"
using namespace std;

class TcpServer;
class Arg{
public:
	string iip;
	int pport;
	int ssock;
	TcpServer* tsp;
};
class TcpServer{
private:
	int listen_sock;
	int port;
	ThreadPool pool;//加入线程池
public:
	TcpServer(int _port) :port(_port), listen_sock(-1)
	{}
	void InitServer()
	{
		listen_sock = socket(AF_INET, SOCK_STREAM, 0);
		if (listen_sock < 0){
			cerr << "listen_sock error" << endl;
			exit(2);
		}
		int opt = 1;
		setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
		struct sockaddr_in local;
		bzero(&local, sizeof(local));
		local.sin_family = AF_INET;
		local.sin_port = htons(port);
		local.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY
		if (bind(listen_sock, (struct sockaddr*)&local, sizeof(local)) < 0){
			cout << "bind error " << endl;
			exit(3);
		}
		if (listen(listen_sock, 5) < 0){
			cout << "listen error" << endl;
			exit(4);
		}
		//signal(SIGCHLD, SIG_IGN);
		pool.InitThreadPool();
	}
	static void Service(int sock)
	{
		char buf[1024];
		while (1){
			ssize_t s = read(sock, buf, sizeof(buf)-1);
			if (s > 0){
				buf[s] = 0;
				write(sock, buf, strlen(buf));
			}
			else if (s == 0){
				cout << "client quit!" << endl;
				break;
			}
			else{
				cerr << "read error" << endl;
				break;
			}
		}
		close(sock);
	}
	void Start()
	{
		struct sockaddr_in peer;
		socklen_t len;
		for (;;){
			len = sizeof(peer);
			int sock = accept(listen_sock, (struct sockaddr*)&peer, &len);
			if (sock < 0){
				cerr << "accept error" << endl;
				continue;
			}
			std::cout << " Get a new client " << sock << endl;
			Task t;
			t.InitTask(sock, Service);
			pool.PushTask(t);
		}
	}
	~TcpServer()
	{
		if (listen_sock > 0)
			close(listen_sock);
	}
};

#include<iostream>
#include<pthread.h>
#include<queue>
using namespace std;

typedef void(*handler_t)(int);
class Task{//任务队列
private:
	int sock;
	handler_t handler;
public:
	Task()
	{

	}
	void InitTask(int _sock, handler_t _h)
	{
		sock = _sock;
		handler = _h;
	}
	void Run()
	{
		handler(sock);
	}
	~Task()
	{

	}
};
class ThreadPool{
private:
	int thread_nums;//线程池中的线程总数
	int idle_nums;//当前闲置线程的数量
	queue<Task> task_queue;//线程所要处理的任务队列
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
		idle_nums++;//一旦进入等待状态闲置线程加一
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
	void InitThreadPool()//创建所需要的线程
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
