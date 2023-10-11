#include "Banque.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void transfertWork(pr::Banque &b){
	::srand(::time(nullptr));
	for(int boucle = 0; boucle < 1000; boucle++){
		unsigned int m = rand()%100 + 1;
		unsigned int i = rand()%b.size() + 1;
		unsigned int j = rand()%b.size() + 1;
		b.transfert(i, j, m);
		unsigned sleep((rand()%21)/1000);
	}
}

const int NB_THREAD = 10;
int main () {
	vector<thread> threads;
	int taille = 100;
	pr::Banque b(taille,1000);
	threads.reserve(NB_THREAD);
	for(int i = 0; i < NB_THREAD; i++){
		threads.emplace_back(transfertWork,ref(b));
	}
	for (auto & t : threads) {
		t.join();
	}

	for(int i = 0; i < 100 ; i++){
		cout<<b.getSoldeCompte(i)<<endl;
	}
	return 0;
}
