#pragma once

#include "Compte.h"
#include <vector>

using namespace std;
namespace pr {

class Banque {
    recursive_mutex mtx;
    mutable mutex m;
    mutex compteDejaVuMutex;
	typedef vector<Compte> comptes_t;
	comptes_t comptes;
    public :
    	Banque (size_t ncomptes, size_t solde) : comptes (ncomptes, Compte(solde)){
    	}
    	void transfert(size_t deb, size_t cred, unsigned int val) ;
    	size_t size() const ;
    	bool comptabiliser (int attendu) const ;
    	comptes_t getCompte() {return comptes;}
    	int getSoldeCompte(int i) const;
    };
}
