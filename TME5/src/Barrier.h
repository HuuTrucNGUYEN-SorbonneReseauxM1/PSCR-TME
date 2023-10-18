#ifndef BARRIER_H_
#define BARRIER_H_

#include <mutex>
#include <condition_variable>
#include <cstdlib>
#include <thread>
using namespace std;

class Barrier{
	int counter;
	const int max;
	mutex m;
	condition_variable cv;

public:
	Barrier(int max): max(max), counter(0){}
	void done(){
		unique_lock <mutex> lg(m);
		counter++;
		if(counter == max){
			cv.notify_all();
		}
	}
	void waitFor(){
		unique_lock <mutex>	lg(m);
		while(counter != max){
			cv.wait(lg);
		}
	}
};

#endif /* BARRIER_H_ */
