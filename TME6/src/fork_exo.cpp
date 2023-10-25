#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "rsleep.h"
using namespace std;
int pv = 3;

void attaque(pid_t adversaire){
	signal(SIGINT,[](int signal){
		if(signal == SIGINT){
			pv--;
			cout<<"pv = "<<pv<<endl;
		}
		if(pv == 0){
			kill(adversaire,SIGINT);
			exit(1);
		}
	});
	kill(adversaire, SIGINT);
	while(true){
		cout<<"Attaque ratee"<<endl;
		exit(1);
	}
	randsleep();
}

void defense(){
	signal(SIGINT,SIG_IGN);
	randsleep();
}

void combat(pid_t adversaire){
	while(true){
		defense();
		attaque(adversaire);
	}
}

int main () {
	int proc = 0;
	const int N = 3;
	std::cout << "main pid=" << getpid() << std::endl;
	for (int i=1, j=N; i<=N && j==N; i++ ) {
		if(fork() != 0){
			proc++;
			break;
		}else{
			proc = 0;
		}
		std::cout << " i:j " << i << ":" << j << std::endl;
		for (int k=1; k<=i && j==N ; k++) {
			if ( fork() == 0) {
				proc = 0;
				j=0;
				std::cout << " k:j " << k << ":" << j << std::endl;
			}else{
				proc++;
			}
		}
	}
	for(int i = 0 ; i < proc ; i++){
		int time = wait(nullptr);
		cout<<"time = "<<time<<endl;
	}
	return 0;
}
