#include "Compte.h"
#include <iostream>
#include <mutex>
using namespace std;

namespace pr {
	void Compte::lock() const {
        m.lock();
    }

    void Compte::unlock() const {
        m.unlock();
    }

    void Compte::crediter (unsigned int val) {
    	unique_lock<mutex> g(m);
    	solde+=val ;
    }
    bool Compte::debiter (unsigned int val) {
    	unique_lock<mutex> g(m);
    	bool doit = solde >= val;
    	if (doit) {
    		solde-=val ;
    	}
    	return doit;
    }
    int Compte::getSolde() const  {
    	unique_lock<mutex> g(m);
    	return solde;
    }
    Compte::Compte(const Compte & other) {
    	other.lock();
    	solde = other.solde;
    	other.unlock();
    }
}
