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
	pid_t pere = getpid();
	pid_t fils = fork();
	srand(fils);
	if(flis == 0){
		combat(pere);
	}else{
		combat(fils);
	}
	return 0;
}
/*
Queston 6
	Ce n'est pas equtable car l n'y a pas de synchronisatio entre l'attaque et la defense, c'est un combat desordonnee
*/
