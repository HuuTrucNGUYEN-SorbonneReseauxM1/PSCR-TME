#pragma once
#include <thread>
#include <mutex>

using namespace std;

namespace pr {
	class Compte {
		mutable mutex m;
		int solde;

	public:
	    void lock() const;
        void unlock() const;
		Compte(int solde = 0) : solde(solde) {}
		Compte(const Compte &other);
		void crediter(unsigned int val);
		bool debiter(unsigned int val);
		int getSolde() const;
	};
}
