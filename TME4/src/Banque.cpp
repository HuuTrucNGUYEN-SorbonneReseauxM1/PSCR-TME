#include "Banque.h"
#include <set>
#include <iostream>

using namespace std;
set<size_t> comptesDejaVus;

namespace pr {
    void Banque::transfert(size_t deb, size_t cred, unsigned int val) {
        unique_lock<recursive_mutex> lock(mtx);
    	Compte & debiteur = comptes[deb];
    	Compte & crediteur = comptes[cred];
    	unique_lock<mutex> lockCompteDejaVu(compteDejaVuMutex);
    	if (comptesDejaVus.find(deb) == comptesDejaVus.end()) {
            comptesDejaVus.insert(deb);
            if (debiteur.debiter(val)) {
                crediteur.crediter(val);
            }
        }else if(debiteur.debiter(val)){
    		crediteur.crediter(val);
    	}
    }
    size_t Banque::size() const {
    	return comptes.size();
    }
    bool Banque::comptabiliser(int attendu) const {
        unique_lock<mutex> lock(m);
        int bilan = 0;
        int id = 0;
        for (const auto &compte : comptes) {
            if (compte.getSolde() < 0) {
                cout << "Compte " << id << " en négatif : " << compte.getSolde() << endl;
            }
            bilan += compte.getSolde();
            id++;
    }
    if (bilan != attendu) {
        cout << "Bilan comptable faux : attendu " << attendu << " obtenu : " << bilan << endl;
    }
    return bilan == attendu;
}

    int Banque::getSoldeCompte(int i) const{
	    return comptes[i].getSolde();
    }
}
