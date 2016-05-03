#ifndef __BALANCEDSEARCHTREE_H__
#define __BALANCEDSEARCHTREE_H__

#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include "generic.h"

using namespace std;

namespace alg{
template<typename KEY>
struct NodeRBT{
	KEY key;
	NodeRBT<KEY> *left, *right;
	int N;
	bool color;               //true: red, false: black
	
	NodeRBT(KEY _key, int _N, bool _color){
		key = _key;
		N = _N;
		color = _color;
		left = 0;
		right = 0;
	}
};

template<typename KEY>
class RedBlackBST{
public:
	RedBlackBST():root(NULL){}
	void put(KEY key){
		root = put(root, key);
		root->color = false;
	}
	int depth(){
		return depth(root);
	}
	void print_tree(){
		int dp = depth(root);
		vector<NodeRBT<KEY>* > vec;
		vec.push_back(root);
		cout<<"The depth of the tree is: "<<dp<<endl;
		for(int n=0; n<dp; ++n){
			int space = pow(2, dp-n-1)-1;
			int interval = pow(2, dp-n)-1;
			for(int s=0; s<space; ++s){
				cout<<" ";
			}
			int length = vec.size();
			for(int i=0; i<length; ++i){
				if(NULL==vec[i]){
					cout<<"#";
					vec.push_back(NULL);
					vec.push_back(NULL);
				}
				else{
					cout<<vec[i]->key;
					if(true == vec[i]->color){
						cout<<"*";
					}
					if(NULL!=vec[i]->left){
						vec.push_back(vec[i]->left);
					}
					else{
						vec.push_back(NULL);
					}
					if(NULL!=vec[i]->right){
						vec.push_back(vec[i]->right);
					}
					else{
						vec.push_back(NULL);
					}
				}
				for(int i=0; i<interval; ++i){
					cout<<" ";
				}
			}
			typename vector<NodeRBT<KEY>* >::iterator it;
			it = vec.begin();
			vec.erase(it, it+length);
			cout<<endl;
		}
		cout<<endl;
	}
private:
	NodeRBT<KEY>* put(NodeRBT<KEY>* node, KEY key){
		if(NULL==node){
			return new NodeRBT<KEY>(key, 1, true);
		}
		if(key<node->key){
			node->left = put(node->left, key);
		}
		else if(key>node->key){
			node->right = put(node->right, key);
		}
		else{
			//If node->key == key
		}
		if(isRed(node->right) && !isRed(node->left)){
			node = rotateLeft(node);
		}
		if(isRed(node->left) && isRed(node->left->left)){
			node = rotateRight(node);
		}
		if(isRed(node->left) && isRed(node->right)){
			flipColors(node);
		}
		node->N = 1 + size(node->left) + size(node->right);
		return node;
	}
	bool isRed(NodeRBT<KEY>* node){
		if(NULL==node){
			return false;
		}
		return node->color==true;
	}
	int size(NodeRBT<KEY>* node){
		if(NULL==node){
			return 0;
		}
		return node->N;
	}
	void flipColors(NodeRBT<KEY>* node){
		node->color = true;
		node->left->color = false;
		node->right->color = false;
	}
	NodeRBT<KEY>* rotateLeft(NodeRBT<KEY>* node){
		NodeRBT<KEY>* right = node->right;
		node->right = right->left;
		right->left = node;
		right->color = node->color;
		node->color = true;
		right->N = node->N;
		node->N = 1+size(node->left)+size(node->right);
		return right;
	}
	NodeRBT<KEY>* rotateRight(NodeRBT<KEY>* node){
		NodeRBT<KEY>* left = node->left;
		node->left = left->right;
		left->right = node;
		left->color = node->color;
		node->color = true;
		left->N = node->N;
		node->N = 1 + size(node->left) + size(node->right);
		return left;
	}
	int depth(NodeRBT<KEY>* node){
		if(NULL==node){return 0;}
		int subDepth = depth(node->left) > depth(node->right) ? depth(node->left) : depth(node->right);
		return 1+ subDepth;
	}
private:
	NodeRBT<KEY>* root;
};
}
#endif