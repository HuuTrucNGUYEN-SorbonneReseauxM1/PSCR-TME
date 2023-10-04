#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>

int main () {
	using namespace std;
	using namespace std::chrono;

	ifstream input = ifstream("/users/nfs/Etu4/21310174/eclipse-workspace/Test/src/WarAndPeace.txt");

	auto start = steady_clock::now();
	vector<pair<string,int>> vec;
	cout << "Parsing War and Peace" << endl;

	size_t nombre_lu = 0;
	// prochain mot lu
	string word;
	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");
	while (input >> word) {
		bool dejala =false;
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);
		for(auto&pair : vec){
			if(pair.first == word){
				pair.second++;
				dejala = true;
			}
		}

		if(dejala == false){
			vec.emplace_back(word,1);
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

    int war = 0,peace = 0, toto = 0;
    for(auto & pair : vec){
    	if(pair.first == "war"){
    		war = pair.second;
    	}else if(pair.first == "peace"){
    		peace = pair.second;
    	}else if(pair.first == "toto"){
    		toto = pair.second;
    	}
    }

    cout << "nombre de war = " << war << "\nnombre de peace = " << peace << "\nnombre de toto = " << toto << endl;

    return 0;
}


