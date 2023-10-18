#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "Barrier.h"
#include "Color.h"
#include "Rayon.h"
#include "Scene.h"
#include "Vec3D.h"
#include "Sphere.h"

using namespace std;

namespace pr {

class Job {
public:
	virtual void run () = 0;
	virtual ~Job() {};
};


class SleepJob : public Job {
	int calcul (int v) {
		cout << "Computing for arg =" << v << endl;
		// traiter un gros calcul
		this_thread::sleep_for(1s);
		int ret = v % 255;
		cout << "Obtained for arg =" << arg <<  " result " << ret << endl;
		return ret;
	}
	int arg;
	int * ret;
	Barrier *barrier;
public :
	SleepJob(int arg, int * ret, Barrier *bar) : arg(arg), ret(ret), barrier(bar) {}
	void run () {
		* ret = calcul(arg);
		barrier -> done();

	}
	~SleepJob(){}
};

}
