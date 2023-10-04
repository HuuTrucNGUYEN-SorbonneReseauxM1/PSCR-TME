//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int *tab = new int[10];
	for(int i = 0 ; i < 10 ; i++){
		tab[i] = i;
		cout<<tab[i]<<endl;
	}
	delete [] tab;
	return 0;
}
