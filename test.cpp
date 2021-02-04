#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <pthread.h>
#include <time.h>

using namespace std;
typedef void (*sighandler_t)(int);

pthread_mutex_t mutex;

int a = 200;
int b = 100;    //multi_thread mutex

//compute the func's run time
void spend_time(void (*p)()){
    clock_t start, end;
    start = clock();
    p();
    end = clock();
    cout << "spend time: " << end - start << "ms." << endl;
}

//multi-process program
void process(){
    pid_t t = getpid();
    cout << "now pid is: " << t << endl;
    printf("abc");
    pid_t child = fork();
    if(child < 0){
	cout << "error happened" << endl;
    }else if(child == 0){
	cout << "child fork:" << getpid()<<endl;
	pid_t cchild = fork();
	if(cchild < 0)cout << "error2 happened" << endl;
	else if(cchild == 0)
		cout << "cchild pid :" << getpid()<< endl;
	else if(cchild >0)
		cout << "final pid:" << getpid() << endl;
	sleep(30);
	cout << "child fork end." << endl;

    }else{
	cout << "father fork :" << getpid() << endl;
	sleep(10);
//	exit(1);
    }
}

//daemon process 
void daetest(){
    daemon(1, 1);
    int i=0;
    while(i<50){
    cout << "daetest:" << i << endl;
    ofstream f("test_d.log",ios::app);
    if(!f.is_open())cout << "error opening file"<< endl;
    f.write("test\n",strlen("test\n"));
    sleep(1);
    f.close();
    i++;
    }
    
}

//mutex pthread
void* mutex_thread(void *){
    for(int i=0;i<10000000;i++){
	pthread_mutex_lock(&mutex);
	a += 50;
	b -= 50;
	pthread_mutex_unlock(&mutex);
    }
}

void* mutex_thread_read(void *){
    while(1){
	pthread_mutex_lock(&mutex);
	cout << a+b << endl;
	pthread_mutex_unlock(&mutex);
	sleep(1);
    }
}

void signal_handler_fun(int signum){
    cout << "catch signal :" << signum << endl;
}

//accept and ignore the signal
void sig_nal(){
    //signal(SIGINT, SIG_IGN);
    signal(SIGINT, signal_handler_fun);
    cout << "ignore the ctrl+c signal ..." << endl;
    //while(1);
    sleep(15);
    //signal(SIGINT, SIG_DFL);
    cout << "restore the default set signal deal method" << endl;
    sleep(5);
}

//pthread multi_params
typedef struct{
    int n;
    const char *str;
}multi_params;

void *thread_func(void *arg){

    sleep(1);
    cout << "start thread" << endl;
    //char *pn = (char*)(arg);
    multi_params *p = (multi_params*) arg;
    for(int i=0;i<2;i++) 
        cout << "n is : " << p->n << endl << p->str << endl;
    return (void*)0;

}



int main(int argc,char* argv[]){
    cout << "params num: " << argc <<endl;
    for(int i=0;i<argc;i++){
	cout << i << " is " << argv[i] << endl;
    }
    const char *te = "-p";
    if(argc == 0)
	cout << "usage: -p is display all";
    else if(argc == 2 && (strcmp(argv[1], "-p")==0)){
	cout << "test ok" << endl;
	process();
    }else if(argc ==2 && strcmp(argv[1], "-d")==0){
	cout << "daemon start:"<< endl;
	daetest();
    }else if(argc == 2 && strcmp(argv[1], "-s")==0){
	cout << "signal test:" << endl;
	sig_nal();
    }else if(argc == 2 && strcmp(argv[1], "-t")==0){
	cout << "pthread test:" << endl;
	pthread_t pid;
	multi_params params;
	params.n = 100;
	params.str = "string";
	int ret = pthread_create(&pid, NULL, thread_func, (void*)&params);
	if(ret){
	     cout << "create error" << ret << endl;
	     return -1;
	}
	sleep(0.1);
	pthread_join(pid, NULL);
	cout << "main thread end" << endl;
    }else if(argc == 2 && strcmp(argv[1], "-t_d")==0){//新建可分离的线程(主线程无需join也可回收资源)
	pthread_t pid;
	pthread_attr_t thread_attr;
	struct sched_param thread_param;
	size_t stack_size;
	int res = pthread_attr_init(&thread_attr);
	if(res)
	    cout << "pthread_attr_init failed." << res <<endl;
	//设置可分离属性
	res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
	if(res)
	    cout << "pthread_attr_setdetachstate failed:"<<res << endl;
	multi_params params;
	params.n = 100;
	params.str = "string";
	res = pthread_create(&pid, &thread_attr, thread_func, (void*)&params);
	if(res)
	    cout << "pthread_create failed:" << res << endl;
	cout << "main thread will exit"<< endl;
	pthread_exit(NULL);//主线程退出,但进程不会此刻退出，下面的语句不会再执行，因此子线程会继续执行
	cout << "test" ;
	//sleep(1);
    }else if(argc == 2 && strcmp(argv[1], "-t_td")==0){
        cout << "pthread test:" << endl;
        pthread_t pid;
        multi_params params;
        params.n = 100;
        params.str = "string";
        int ret = pthread_create(&pid, NULL, thread_func, (void*)&params);
        if(ret){
             cout << "create error" << ret << endl;
             return -1;
        }
//      sleep(1);
	pthread_detach(pid);//非阻塞，可立即返回,将可连接线程更改为可分离线程
	//或者在函数中运行pthread_detach(pthread_self());
        //pthread_join(pid, NULL);
        cout << "main thread end" << endl;
	//sleep(1);
    }else if(argc == 2 && strcmp(argv[1], "-t_m")==0){
	pthread_mutex_init(&mutex, NULL);
	pthread_t ta, tb;
	pthread_create(&ta, NULL, mutex_thread, NULL);
	pthread_create(&tb, NULL, mutex_thread_read, NULL);
	pthread_join(ta, NULL);
	pthread_join(tb, NULL);
	pthread_mutex_destroy(&mutex);
    }

    return 0;
}
