#ifndef __BALANCEDSEARCHTREE_H__
#define __BALANCEDSEARCHTREE_H__

#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include "generic.h"

using namespace std;

namespace alg{
template<typename KEY, typename VALUE>
struct Node23{
	KEY lkey, rkey;
	VALUE lvalue, rvalue;
	int size;
	int N;
	Node23<KEY, VALUE>* left;
	Node23<KEY, VALUE>* mid;
	Node23<KEY, VALUE>* right;
	
	Node23(KEY _key1, VALUE _lvalue, int _size, int _Nt){
		lkey = _key1;
		rkey = KEY();
		lvalue = _lvalue;
		rvalue = VALUE();
		N = _Nt;
		size = _size;
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
			for(int s=0; s<space; ++s){cout<<" ";}
			for(int i=0; i<size; ++i){
				Node23<KEY, VALUE>* node = vec[i];
				if(NULL==node){
					vec.push_back(NULL);
					vec.push_back(NULL);
					vec.push_back(NULL);
					cout<<"#_#";
				}
				else{
					if(NULL==node->lkey){
						cout<<" AAA ";
						cout<<"#";
					}
					else{
						cout<<node->lkey;
					}
					cout<<"_";
					if(NULL==node->rkey){
						cout<<"#";
					}
					else{
						cout<<node->rkey;
					}
					vec.push_back(NULL==node->left?NULL:node->left);
					vec.push_back(NULL==node->mid?NULL:node->mid);
					vec.push_back(NULL==node->right?NULL:node->right);
				}
				for(int j=0; j<interval; ++j){cout<<" ";}
			}
			cout<<endl;
			typename vector<Node23<KEY, VALUE>* >::iterator it;
			it = vec.begin();
			vec.erase(it, it+size);
		}
	}
private:
	int depth(Node23<KEY, VALUE>* node){
		if(NULL==node){return 0;}
		int curdepth = (depth(node->left)>=depth(node->mid) && depth(node->left)>=depth(node->right))?depth(node->left):(depth(node->mid)>=depth(node->right)?depth(node->mid):depth(node->right));
		return 1 + curdepth;
	}
	int size(Node23<KEY, VALUE>* node){
		if(NULL==node){
			return 0;
		}
		return node->N;
	}
	Node23<KEY, VALUE>* put(Node23<KEY, VALUE>* node, KEY key, VALUE value){
		if(NULL == node){
			return new Node23<KEY, VALUE>(key, value, 1, 1);
		}
		if(root == node){
			if(root->lvalue > key){
				root->left = put(root->left, key, value);
			}
			else{
				root->right = put(root->right, key, value);
			}
		}
		return node;
	}
private:
	Node23<KEY, VALUE>* root;
};
}
#endif