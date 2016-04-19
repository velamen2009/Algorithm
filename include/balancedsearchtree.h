#ifndef __BALANCEDSEARCHTREE_H__
#define __BALANCEDSEARCHTREE_H__

#include<iostream>
#include<vector>
#include<math.h>
#include "generic.h"

using namespace std;

namespace alg{
template<typename KEY, typename VALUE>
struct Node23{
	KEY key;
	VALUE value;
	int N;
	Node23<KEY, VALUE>* left;
	Node23<KEY, VALUE>* mid;
	Node23<KEY, VALUE>* right;
	Node23(KEY _key, VALUE _value, int _N){
		key = _key;
		value = _value;
		N = _N;
		left = 0;
		mid = 0;
		right = 0;
	}
};

template<typename KEY, typename VALUE>
class BalancedSearchTree{
public:
	BalancedSearchTree():root(0){}
	void put(KEY key, VALUE value){
		root = put(root, key, value);
	}
	void print_tree23(){
		int thedepth = depth(root);
		cout<<"The depth of the balanced tree is: "<<thedepth<<endl;
		vector<Node23<KEY, VALUE>* > vec;
		vec.push_back(root);
		for(int n=0; n<thedepth; ++n){
			int space = pow(2, thedepth-n) -2;
			int interval = pow(2, thedepth-n+1)-3;
			int size = vec.size();
			for(int i=0; i<size; ++i){
				
			}
			typename vector<Node23<KEY, VALUE>* >::iterator it;
			
		}
	}
private:
	int depth(Node23<KEY, VALUE>* node){
		if(NULL==node){return 0;}
		int curdepth = (depth(node->left)>=depth(node->mid) && depth(node->left)>=depth(node->right))?depth(node->left):(depth(node->mid)>=depth(node->right)?depth(node->mid):depth(node->right));
		return 1 + curdepth;
	}
	Node23<KEY, VALUE>* put(Node23<KEY, VALUE>* node, KEY key, VALUE value){
		if(NULL == node){
			return new Node23<KEY, VALUE>(key, value, 1);
		}
		return NULL;
	}
private:
	Node23<KEY, VALUE>* root;
};
}
#endif