#pragma once
#include<forward_list>
#include<vector>
using namespace std;
namespace pr {
	template <typename K, typename V>

class Hashtable{
	public:
		class Entry{
			public:
			const K key;
			V value;
			Entry(const K& key, V& value): key(key),value(value){}
		};

	private:
		typedef vector<forward_list<Entry>> bucket_t;
		bucket_t buckets;
		size_t size;

	public:
		Hashtable(size_t sz): size(0), buckets(sz){}
		V * get (const K& key){
			size_t target = hash<K>()(key);
			for(Entry e : buckets[target]){
				if(e.key == key){
					return &e.value;
				}
			}
			return nullptr;
		}

		bool put (const K& key, const V& value){
			size_t h = hash<K>()(key);
			size_t target = h % buckets.size();
			for(Entry &e : buckets[target]){
				if(e.key == key){
					e.value = value;
					return true;
				}
			}
			size++;
			buckets[target].empalce.front(key,value);
			return false;
		}
	};
}

#ifndef HASTABLE_H_
#define HASTABLE_H_





#endif /* HASTABLE_H_ */
