#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>

/*int main () {
	using namespace std;
	using namespace std::chrono;

	ifstream input = ifstream("C:/Users/nguye/eclipse-workspace/TestC++/src/WarAndPeace.txt");

	auto start = steady_clock::now();
	vector<string> vec; //crée le vecteur
	cout << "Parsing War and Peace" << endl;

	size_t nombre_lu = 0;
	// prochain mot lu
	string word;
	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");
	while (input >> word) {
		bool dejala = false;
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);
		for(string s : vec){

			if(word == s){
				dejala = true;
			}
		}
		if(dejala == false){
			vec.push_back(word);
			if (nombre_lu % 100 == 0)
				// on affiche un mot "propre" sur 100
				cout << nombre_lu << ": "<< word << endl;
			nombre_lu++;
		}

	}
	input.close();

	cout << "Finished Parsing War and Peace" << endl;

	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

    cout << "Found a total of " << nombre_lu << " words." << endl;

    return 0;
}*/


