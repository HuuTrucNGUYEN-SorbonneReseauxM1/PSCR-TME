#include<iostream>
#include"Hashtable.h"
using namespace std;
using namespace pr;
template <typename iterator>
size_t count (iterator begin, iterator end){
	size_t count = 0;
	while(begin != end){
		count++;
		++begin;
	}
	return count;
}

template <typename iterator, typename T>
size_t count_if_equal (iterator begin, iterator end, const T &val){
	size_t count  = 0;
	while(begin != end){
		if(*begin == val){
			count++;
		}
		++begin;
	}
	return count;
}

int main(){
	int arr[] = {1,2,3,2,2,4,5,6};
	int val = 2;
	size_t res = count(arr, arr+sizeof(arr)/sizeof(arr[0]));
	size_t res2 = count_if_equal(arr, arr+sizeof(arr)/sizeof(arr[0]), val);
	cout<<"res = "<<res<<"\nres2 = "<<res2<<endl;
	Hashtable<int, int> *h;
	return 0;
}
