#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <pthread.h>
#include <mutex>
#include <thread>



using namespace std;

pthread_mutex_t amutex;

void runfunc(void (*p)())
{
	clock_t start, end;
	start = clock();
	p();	
	end = clock();
	cout << end-start << endl;
}



void add()
{
	int a = 100;
	int b = 50;
	a += b;
	cout<<"a+b: " << a+b<<endl;
}
int a = 5;
int b = 5;

void* func1(void *arg){
    pthread_mutex_lock(&amutex);
    if(a==5){
	//cout << "a" << a << "|||||||||||||||||||||"<<a<< endl;
	a = 6;
    }
    pthread_mutex_unlock(&amutex);
}

void* func2(void *arg){
    pthread_mutex_lock(&amutex);
    a += 2;
    pthread_mutex_unlock(&amutex);
}

int test(){
	//execlp("test","ls","-p", NULL);
	//int ans = system("test");
	//cout << endl << "process end;" << ans << endl;
	//runfunc(add);
	pthread_mutex_init(&amutex, NULL);
	pthread_t t1, t2;
	for(int i=0; i<1000000;i++){
		pthread_create(&t1, NULL, func1, NULL);
		pthread_create(&t2, NULL, func2, NULL);
		//pthread_create(&t1, NULL, func1, NULL);
		pthread_join(t1, NULL);
		pthread_join(t2, NULL);
		//cout << "a: " << a << " b: " << b << endl;
		if(a==6) cout << a << "yes"<< endl;
		a = 5;
		b = 5;
	}
	pthread_mutex_destroy(&amutex);


	return 1;
}

std::mutex mtx;
int counter = 0;

void thrfunc(){
	for(int i=0;i<10000;i++){
		if(true){
			mtx.lock();
			++counter;
			mtx.unlock();
		}
		else std::cout << "try_lock false\n";
	}
}

class Test(){
	static int te;
	void prin(int num){};
}

Test::prin(int num){
	cout << te;
}

int main(){
/*
	std::thread threads[10];
	for(int i=0;i<10;++i){
		threads[i] = thread(thrfunc);
	}
	for(auto &th: threads) th.join();
	cout << "count to" << counter << endl;
	return 0;
*/
	Test::te = 2;
	Test.prin(3);
}
