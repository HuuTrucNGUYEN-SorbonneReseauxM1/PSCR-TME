#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
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
