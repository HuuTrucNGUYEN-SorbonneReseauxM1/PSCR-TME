#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <chrono>
#include <algorithm>
#include "HashMap.h"

using namespace std;
using namespace std::chrono;
using namespace pr;

int main() {
	HashTable<string, int> map(100);
	auto start = steady_clock::now();

	ifstream input("C:/Users/nguye/eclipse-workspace/TestC++/src/WarAndPeace.txt");
	if (!input.is_open()) {
		cerr << "Failed to open the input file." << endl;
		return 1;
	}

	string word;
	regex re("[\\W_]+");

	int nombre_lu = 0;

	while (input >> word) {
		word = regex_replace(word, re, "");
		transform(word.begin(), word.end(), word.begin(), ::tolower);

		int* val = map.get(word);
		if (val) {
			(*val)++;
		} else {
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
	int num = 0;
	vector<pair<string, int>> wordCounts;
	for (HashTable<string, int>::Iterator it = map.begin(); it != map.end(); ++it) {
		wordCounts.push_back({(*it).key, (*it).value});
	}

	sort(wordCounts.begin(), wordCounts.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
		return a.second > b.second;
	});

	for (HashTable<string, int>::Iterator it = map.begin(); it != map.end(); ++it) {
		cout << (*it).key << ": " << (*it).value << endl;
		num++;
	}
	for(int i = 0; i < 10; i++){
				cout<<wordCounts[i].first<<" :"<<wordCounts[i].second<<endl;
			}
	cout << "Found a total of " << num << " unique words." << endl;

	return 0;
}
