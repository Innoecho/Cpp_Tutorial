#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <string>

using namespace std;

#define NUM_THREADS 5

struct thread_data
{
	int thread_id;
	string message;
};

void* PrintHello(void* threadarg)
{
	struct thread_data *data;
	data = (thread_data*)threadarg;

	cout << "Thread ID: " << data->thread_id;
	cout << " Message: " << data->message << endl;

	pthread_exit(NULL);
}

int main()
{
	pthread_t tids[NUM_THREADS];
	thread_data td[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		cout << "main(): Create Thread, " << i << endl;
		td[i].thread_id = i;
		td[i].message = "Hello World!";
		// 创建线程，注意参数传入时的强制类型转换
		int ret = pthread_create(&tids[i], NULL, PrintHello, (void*)&td[i]);
		if (ret)
		{
			cout << "pthread_create error: error_code = " << ret << endl;
			exit(-1);
		}
		sleep(1);
	}
	pthread_exit(NULL);
}