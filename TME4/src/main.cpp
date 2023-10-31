#include "Banque.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;
using namespace std;
using namespace pr;
const int NB_THREAD = 10;
int SOLDEINITIAL = 100000;

int transfertWork(Banque &b){
	for(int boucle = 0; boucle < 1000; boucle++){
	    unsigned int m = rand()%100 + 1;
		size_t i = rand()%b.size() + 1;
		size_t j = rand()%b.size() + 1;
		b.transfert(i, j, m);
		return 0;
		this_thread::sleep_for(milliseconds(rand() % 21));
	}
	return 0;
}

int main () {
    ::srand(::time(nullptr));
	vector<thread> threads;
	int taille = 100;
	Banque b = Banque(taille,1000);
	threads.reserve(NB_THREAD);
	for(int i = 0; i < NB_THREAD; i++){
		threads.emplace_back(transfertWork,ref(b));
	}
	for (auto & t : threads) {
		t.join();
	}
	int x = 0;
    for(int i = 0; i < 100 ; i++){
        x += b.getSoldeCompte(i);
		cout<<b.getSoldeCompte(i)<<endl;
	}
	b.comptabiliser(SOLDEINITIAL);
	cout<<"\nTotal: "<<x<<endl;
	return 0;
}
