#pragma once

#include "Queue.h"
#include "Job.h"
#include <vector>
#include <thread>

namespace pr {

class Pool {
	Queue<Job> queue;
	std::vector<std::thread> threads;
public:
	Pool(int qsize) ;
	void poolWorker(Queue<Job> &queue){
		while(true){
			Job *pjob = queue.pop();
			if(pjob == nullptr){
				return ;
			}
			pjob -> run();
			delete pjob;
		}
	}
	void start (int nbthread){
		threads.reserve(nbthread);
		for(int i = 0 ; i < nbthread ; i++){
			threads.emplace_back(poolWorker, &queue);
		}
	}
	void submit (Job * job){
		queue.push(job);
	}
	void stop() {
		queue.isBlocking(false);
		for(auto &t : threads){
			t.join();
		}
		threads.clear();
	}
	~Pool(){
		stop();
	}
};

}
