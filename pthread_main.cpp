#include "pthread_pool.h"
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

class CMyTask : public CTask {

public:
	CMyTask() = default;
	int Run(){
		cout << "m_pthData: " << (char*)m_ptrData << endl;
		int x = rand() % 4 + 1;
		sleep(x);
		return 0;
	}
	~CMyTask(){}

};

int main(){

	CMyTask taskObj;
	char szTmp[] = "hello!";
	taskObj.setData((void*)szTmp);
	CThreadPool threadpool(5); //线程池大小为5
	
	for ( int i = 0; i < 10; i++ )
		threadpool.AddTask(&taskObj);
	
	while(1) {
		cout << "There are still " << threadpool.getTaskSize() << " tasks need to handle" << endl;
		//任务队列已经没任务了
		if (threadpool.getTaskSize() == 0){
			//清楚线程池
			if (threadpool.StopAll() == -1){
				cout << "Thread pool clear, exit" << endl;
				exit(0);
			}
		}
		sleep(2);
		cout << "2 seconds later...\n";
	}

	return 0;
}
