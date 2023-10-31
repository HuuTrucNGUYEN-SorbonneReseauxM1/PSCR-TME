#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>
#include "HashMap.h"

/*(int main() {
    using namespace pr;
    using namespace std;
    using namespace std::chrono;

    ifstream input("C:/Users/nguye/eclipse-workspace/TestC++/src/WarAndPeace.txt");

    if (!input.is_open()) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }
    size_t t;
    auto start = steady_clock::now();
    HashTable<string, int> map(t);
    cout << "Parsing War and Peace" << endl;

    size_t nombre_lu = 0;
    string word;
    regex re(R"([^a-zA-Z])");
    int val;
    while (input >> word) {
        word = regex_replace(word, re, "");
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (map.get(word) != nullptr) {
        	val = *map.get(word);
        	map.put(word,val++);
		}else{
			map.put(word, 1);
		}
		if (nombre_lu % 100 == 0)
			cout << nombre_lu << ": " << word << endl;
		nombre_lu++;
    }

    input.close();
    cout << "Finished Parsing War and Peace" << endl;

    auto end = steady_clock::now();
    cout << "Parsing took " << duration_cast<milliseconds>(end - start).count() << "ms.\n";
    cout << "Found a total of " << nombre_lu << " words." << endl;

    return 0;
}*/
