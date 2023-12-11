#pragma once
#include <sys/sem.h>
#include <unistd.h>
#include <cstring> // size_t,memset

namespace pr {

#define STACKSIZE 100

template<typename T>
class Stack {
	T tab [STACKSIZE];
	size_t sz;
	int semid;
	sembuf p_lock[2], v_unlock[2]
public :
	Stack () : sz(0) { 
		memset(tab,0,sizeof tab) ;
		semid = semget(IPC_PRIVATE, 2, IPC_CREAT | 0666);
        	semctl(semid, 0, SETVAL, 1);
        	semctl(semid, 1, SETVAL, STACKSIZE); 

        	p_lock[0] = {0, -1, 0}; //lock	
        	p_lock[1] = {1, -1, 0}; //decrease
        	v_unlock[0] = {0, 1, 0}; //unlock
        	v_unlock[1] = {1, 1, 0}; //increase
	}

	T pop () {
		// bloquer si vide
		semop(semid, &p_lock[0], 1);
        	T toret = tab[--sz];
       		semop(semid, v_unlock, 2); 
        	return toret;
	}

	void push(T elt) {
		//bloquer si plein
		semop(semid, p_lock, 2); 
        	tab[sz++] = elt;
        	semop(semid, &v_unlock[0], 1);
	}

 	~Stack() {
        	semctl(semid, 0, IPC_RMID);
    	}

	size_t getSz(){
		return sz;
	}

	size_t getSzMax(){
		return STACKSIZE;
	}
};

}
