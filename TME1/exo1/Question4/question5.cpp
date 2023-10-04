#include <iostream>
using namespace std;

int main(){
	int *tab = new int[10];
	for(int i = 0 ; i < 10 ; i++){
		tab[i] = i;
		cout<<tab[i]<<endl;
	}
	for (int i=9; i > 0 ; i--) {
		if (tab[i] - tab[i-1] != 1) {
			cout << "probleme !";
		}
	}
	delete [] tab;
	return 0;
}
