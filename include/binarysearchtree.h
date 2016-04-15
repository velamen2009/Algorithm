#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include<iostream>
#include<vector>
#include<math.h>
#include "generic.h"

using namespace std;

template <typename KEY, typename VALUE>
struct Node{
	KEY key;
	VALUE value;
	int N;
	Node<KEY, VALUE>* left;
	Node<KEY, VALUE>* right;
	
	Node(KEY _key, VALUE _value, int _N){
		key = _key;
		value = _value;
		N = _N;
		left = NULL;
		right = NULL;
	}
};

template <typename KEY, typename VALUE>
class BinarySearchTree{
public:
	BinarySearchTree():root(NULL){}
	int size(){return size(root);}
	int size(Node<KEY, VALUE>* node){
		if(NULL==node){
			return 0;
		}
		return node->N;
	}
	VALUE get(KEY key){
		return get(root, key);
	}
	void put(KEY key, VALUE value){
		root = put(root, key, value);
	}
	void print(){
		if(NULL==root){return;}
		vector<Node<KEY, VALUE>* > vec;
		vec.push_back(root);
		while(!vec.empty()){
			int length = vec.size();
			for(int i=0; i<length; ++i){
				cout<<vec[i]->key<<":"<<vec[i]->value<<":"<<vec[i]->N<<"\t";
				if(NULL!=vec[i]->left){
					vec.push_back(vec[i]->left);
				}
				if(NULL!=vec[i]->right){
					vec.push_back(vec[i]->right);
				}
			}
			typename vector<Node<KEY, VALUE>* >::iterator it;
			it = vec.begin();
			vec.erase(it, it+length);
			cout<<endl;
		}
	}
	void print_tree_graph(){
		int dp = depth(root);
		vector<Node<KEY, VALUE>* > vec;
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
				cout<<vec[i]->key<<":"<<vec[i]->value<<":"<<vec[i]->N<<"\t";
				for(int i=0; i<interval; ++i){
					cout<<" ";
				}
				if(NULL!=vec[i]->left){
					vec.push_back(vec[i]->left);
				}
				if(NULL!=vec[i]->right){
					vec.push_back(vec[i]->right);
				}
			}
			typename vector<Node<KEY, VALUE>* >::iterator it;
			it = vec.begin();
			vec.erase(it, it+length);
			cout<<endl;
		}
	}
	int depth(){
		return depth(root);
	}
	KEY min(){
		return min(root)->key;
	}
	KEY floor(KEY key){
		Node<KEY, VALUE>* node = floor(root, key);
		if(NULL==node){return NULL;}
		return node->key;
	}
	void deleteMin(){
		root = deleteMin(root);
	}
	void deleteByKey(KEY key){
		root = deleteByKey(root, key);
	}
private:
	VALUE get(Node<KEY, VALUE>* node, KEY key){
		if(NULL == node){ return NULL; }
		if(node->key == key){ return node->value;}
		if(node->key > key){
			return get(node->left, key);
		}
		else{
			return get(node->right, key);
		}
	}
	
	Node<KEY, VALUE>* put(Node<KEY, VALUE>* node, KEY key, VALUE value){
		if(NULL==node){
			return new Node<KEY, VALUE>(key, value, 1);
		}
		if(node->key==key){
			node->value = value;
			return node;
		}
		else if(node->key>key){
			node->left = put(node->left, key, value);
		}
		else{
			node->right = put(node->right, key, value);
		}
		node->N = size(node->left) + size(node->right) +1;
		return node;
	}
	
	int depth(Node<KEY, VALUE>* node){
		if(NULL==node){return 0;}
		int subDepth = depth(node->left) > depth(node->right) ? depth(node->left) : depth(node->right);
		return 1+ subDepth;
	}
	
	Node<KEY, VALUE>* min(Node<KEY, VALUE>* node){
		if(NULL==node->left){
			return node;
		}
		else{
			return min(node->left);
		}
	}
	
	Node<KEY, VALUE>* floor(Node<KEY, VALUE>* node, KEY key){
		if(NULL==node){return NULL;}
		if(key==node->key){return node;}
		if(key<node->key){return floor(node->left, key);}
		
		Node<KEY, VALUE>* x = floor(node->right, key);
		if(NULL!=x){return x;}
		else{ return node;}
	}
	
	Node<KEY, VALUE>* deleteMin(Node<KEY, VALUE>* node){
		if(NULL==node->left){ return node->right;}
		node->left = deleteMin(node->left);
		node->N = size(node->left) + size(node->right) + 1;
		return node;
	}
	Node<KEY, VALUE>* deleteByKey(Node<KEY, VALUE>* node, KEY key){
		if(NULL==node){return NULL;}
		if(node->key > key){
			node->left = deleteByKey(node->left, key);
		}
		else if(node->right < key){
			node->right = deleteByKey(node->right, key);
		}
		else{
			if(node->right == NULL){return node->left;}
			if(node->left == NULL){return node->right;}
			Node<KEY, VALUE>* t = node;
			node = min(t->right);
			t->right = deleteMin(t->right);
			node->left = t->left;
		}
		node->N = size(node->left) + size(node->right) + 1;
		return node;
	}
private:
	Node<KEY, VALUE>* root;
};

#endif