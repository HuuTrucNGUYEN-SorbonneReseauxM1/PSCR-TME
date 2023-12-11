#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
using namespace std;

int main(int argc, char ** argv){
	/*int pdesc[2];
	pid_t pfils;
	if(pipe(pdesc) == -1){
		perror("pipe");
		exit(1);
	}
	if((pfils = fork()) == -1){
		perror("fork");
		exit(2);
	}
	if(pfils == 0){
		dup2(pdesc[1], STDOUT_FILENO);
		close(pdesc[1]);
		close(pdesc[0]);
		if(execl("/bin/cat", "cat", "pipe.cpp", NULL) == -1){
			perror("execl");
			exit(3);
		}
	}else{
		dup2(pdesc[0], STDIN_FILENO);
		close(pdesc[0]);
		close(pdesc[1]);
		if(execl("/bin/wc", "wc", "-l", NULL) == -1){
			perror("execl");
			exit(3);
		}
	}
	return EXIT_SUCCESS;*/
	int pindex = -1;
	for(int i = 1 ; i < argc ; ++i){
		if(string(argv[i]) == "|"){
			pindex = i;
			break;
		}
	}

	if(pindex == -1 || pindex == argc - 1){
		cerr << "Usage: " << argv[0] << "commande1 | commande2" << endl;
		return 1;
	}

	int pdesc[2];
	if(pipe(pdesc) == -1){
		perror("pipe");
		return 1;
	}

	pid_t pfils = fork();

	if(pfils == -1){
		perror("fork");
		return 1;
	}

	if(pfils == 0){
		close(pdesc[0]);
		dup2(pdesc[1], STDOUT_FILENO);
		close(pdesc[1]);

		char** com1 = argv + 1;
		com1[pindex - 1] = nullptr;

		execvp(com1[0], com1);
		perror("execvp");
	}else{
		waitpid(pfils, nullptr, 0);
		close(pdesc[1]);
		dup2(pdesc[0], STDIN_FILENO);
		close(pdesc[0]);

		char** com2 = argv + pindex + 1;

		execvp(com2[0], com2);
		perror("execvp");
		return 1;
	}
	return 0;
}

