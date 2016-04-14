#ifndef __BINARYSEARCHST_H__
#define __BINARYSEARCHST_H__

#include<iostream>
#include<vector>
#include "generic.h"

using namespace std;

template <typename KEY, typename VALUE>
class BinarySearchST{
public:
	BinarySearchST():size(0){}
	int Size(){return size;}
	bool isEmpty(){return 0==size;}
	VALUE get(KEY key){
		if(isEmpty()){
			return NULL;
		}
		int i=rank(key);
		if(key==keys[i]){
			return values[i];
		}
		return NULL;
	}
	int rank(KEY key){
		int lo=0, hi=size-1;
		while(lo<=hi){
			int mid = (lo+hi)/2;
			if(keys[mid]==key){
				return mid;
			}
			else if(keys[mid]>key){
				hi=mid-1;
			}
			else{
				lo=mid+1;
			}
		}
		return lo;
	}
	void put(KEY key, VALUE value){
		int i=rank(key);
		if(i<size&&key==keys[i]){
			values[i]+=value;
		}
		else{
			 typename vector<KEY>::iterator keyit;
			 keyit=keys.begin();
			 keys.insert(keyit+i, key);
			 typename vector<VALUE>::iterator valueit;
			 valueit=values.begin();
			 values.insert(valueit+i, value);
			 ++size;
		}
	}
	void deletekey(KEY key){
		int i=rank(key);
		if(i<size&&key==keys[i]){
			 typename vector<KEY>::iterator keyit;
			 keyit=keys.begin();
			 keys.erase(keyit+i);
			 typename vector<VALUE>::iterator valueit;
			 valueit=values.begin();
			 values.erase(valueit+i);
			 --size;
		}
	}
	KEY min(){
		return keys[0];
	}
	KEY max(){
		return keys[size-1];
	}
	void print(){
		for(int i=0; i<size; ++i){
			cout<<keys[i]<<" => "<<values[i]<<endl;
		}
	}
	
private:
	vector<KEY> keys;
	vector<VALUE> values;
	int size;
};

#endif