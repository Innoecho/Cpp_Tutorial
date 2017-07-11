#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void* wait(void* t)
{
	int tid;

	tid = *(int*)t;

	sleep(5-tid);
	cout << "Sleeping in thread " << endl;
	cout << "Thread with id: " << tid << " ...exiting " << endl;
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	void* status;
	int ret;

	// 初始化并设置线程为可连接的(joinable)
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		cout << "main(): Create Thread, " << i << endl;
		// 创建线程，注意参数传入时的强制类型转换
		ret = pthread_create(&threads[i], &attr, wait, (void*)&i);
		if (ret)
		{
			cout << "pthread_create error: error_code = " << ret << endl;
			exit(-1);
		}
	}

	// 删除属性，并等待其他线程
	pthread_attr_destroy(&attr);
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		ret = pthread_join(threads[i], &status);
		if (ret)
		{
			cout << "Error: unable to join," << ret << endl;
			exit(-1);
		}
		cout << "Main: completed thread id: " << i;
		cout << "  exiting with status: " << status << endl;
	}

	cout << "Main: program exiting" << endl;
	pthread_exit(NULL);
}