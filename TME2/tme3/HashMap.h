#ifndef HASHMAP_H_
#define HASHMAP_H_
#pragma once
#include <forward_list>
#include <vector>
#include <iostream>
using namespace std;
namespace pr{

template<typename K, typename V>
	class HashTable{
		public:
			class Entry{
				public:
					const K key;
					V value;
					Entry(const K& key, const V& value) : key(key), value(value) {}
				};
			typedef std::vector<std::forward_list<Entry>> bucket_t;

			    class Iterator {
			    private:
			        typename bucket_t::iterator vect;
			        typename std::forward_list<Entry>::iterator list;
			        std::vector<std::forward_list<Entry>>& buckets;

			    public:
			        Iterator(std::vector<std::forward_list<Entry>>& elem, bool end = false) : buckets(elem) {
			            if (end) {
			                vect = buckets.end();
			            } else {
			                vect = buckets.begin();
			                if (vect != buckets.end()) {
			                    list = vect->begin();
			                }
			            }
			        }

			        bool operator!=(const Iterator& other) const {
			            return vect != other.vect || (vect != buckets.end() && list != other.list);
			        }

			        Iterator& operator++() {
			            if (vect != buckets.end()) {
			                ++list;
			                if (list == vect->end()) {
			                    do {
			                        ++vect;
			                    } while (vect != buckets.end() && vect->empty());
			                    if (vect != buckets.end()) {
			                        list = vect->begin();
			                    }
			                }
			            }
			            return *this;
			        }

			        Entry& operator*() {
			            return *list;
			        }
			    };

		private:
			vector<forward_list<Entry>> buckets;
			size_t size;

		public:
			HashTable(size_t sz) : buckets(sz), size(0) {}

			Iterator begin(){
				return Iterator(buckets);
			}

			Iterator end(){
				return Iterator(buckets, true);
			}

			V* get(const K& key) {
			    size_t h = hash<K>()(key);
			    size_t target = h % buckets.size();
			    for (Entry& e : buckets[target]) {
			        if (e.key == key) {
			            return &e.value;
			        }
			    }
			    return nullptr;
			}

			bool put(const K& key, const V& value){
				size_t h = hash<K>()(key);
				size_t target = h % buckets.size();
				for(Entry &e : buckets[target]){
					if(e.key == key){
						e.value = value;
						return true;
					}
				}
				size++;
				buckets[target].emplace_front(key,value);
				return false;
			}
	};
}


#endif /* HASHMAP_H_ */
