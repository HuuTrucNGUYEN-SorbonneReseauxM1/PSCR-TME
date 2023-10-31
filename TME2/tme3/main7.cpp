#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>
#include <algorithm>
#include "HashMap.h"

/*int main() {
    using namespace pr;
    using namespace std;
    using namespace std::chrono;

    ifstream input("C:/Users/nguye/eclipse-workspace/TestC++/src/WarAndPeace.txt");

    if (!input.is_open()) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    size_t t = 24000;
    auto start = steady_clock::now();
    HashTable<string, int> map(t);
    vector<pair<string, int>> vec;
    cout << "Parsing War and Peace" << endl;
    size_t nombre_lu = 0;
    string word;
    regex re(R"([^a-zA-Z])");

    while (input >> word) {
        word = regex_replace(word, re, "");
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        int* countPtr = map.get(word);
        if (countPtr) {
            (*countPtr)++;
            for (auto& kvp : vec) {
                if (kvp.first == word) {
                    kvp.second = *countPtr;
                }
            }
        } else {
            map.put(word, 1);
            vec.emplace_back(word, 1);
        }

        if (nombre_lu % 100 == 0)
            cout << nombre_lu << ": " << word << endl;
        nombre_lu++;
    }
    input.close();

    for (const auto& kvp : vec) {
        cout << kvp.first << ": " << kvp.second << endl;
    }

    cout << "Finished Parsing War and Peace" << endl;

    auto end = steady_clock::now();
    cout << "Parsing took " << duration_cast<milliseconds>(end - start).count() << "ms.\n";
    cout << "Found a total of " << vec.size() << " words." << endl;
    sort(vec.begin(), vec.end(), [] (const pair<string, int> & a, const pair<string,int>& b){
    	return a.second>b.second;
    });
    for(int i = 0; i < 10; i++){
    	cout<<vec[i].first<<" :"<<vec[i].second<<endl;
    }
    return 0;
}*/
