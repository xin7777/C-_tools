#ifndef __PTHREAD_POOL_H
#define __PTHREAD_POOL_H

#include <vector>
#include <string>
#include <pthread.h>

using namespace std;

class CTask{

protected:
	string m_strTaskName; //task name
	void* m_ptrData; //task data

public:
	CTask() = default;
	CTask(string &taskName)
		: m_strTaskName(taskName)
		, m_ptrData(NULL) {}
	virtual int  Run() = 0;
	void setData(void* data); //set task data
	
	virtual ~CTask(){};

};


//thread manage class
class CThreadPool{

private:
	static vector<CTask*> m_vecTaskList; //task list
	static bool shutdown; //线程退出标志
	int m_iThreadNum; //线程池中启动的线程数
	pthread_t *pthread_id;
	
	static pthread_mutex_t m_pthreadMutex; //thread mutex
	static pthread_cond_t m_pthreadCond;  //线程同步条件变量

protected:
	static void* ThreadFunc(void *threadData); //新线程的线程回调函数
	static int MoveToIdle(pthread_t tid); //线程执行结束后，把自己放入空闲线程中
	static int MoveToBusy(pthread_t tid); //移入到忙碌线程中去
	int Create(); //创建线程池中的线程

public:
	CThreadPool(int threadNum);
	int AddTask(CTask *task); //把任务添加到任务队列中
	int StopAll(); //把线程池中的所有线程退出
	int getTaskSize(); //获取当前任务队列中的任务数

};


#endif
