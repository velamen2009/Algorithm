#include <cstdlib>
#include <iostream>
#include <time.h>
#include "../include/binarysearchtree.h"

using namespace std;
using namespace alg;

int main(){
	BinarySearchTree<char, int> bst;
	srand(time(NULL));
	for(int i=0; i<500; ++i){
		char key = rand()%26+65;
		bst.put(key, i);
	}
	cout<<"The binary search tree:"<<endl;
	bst.print();
	bst.print_tree_graph();
	
	cout<<"The size of tree:"<<endl;
	cout<<bst.size()<<endl;
	
	cout<<"The minimum key is:"<<endl;
	cout<<bst.min()<<endl;
	
	cout<<"Delete minimum key:"<<endl;
	for(int i=0; i<20; ++i){
		bst.deleteMin();
	}
	bst.print_tree_graph();
	
	cout<<"The floor of 'Y' is:"<<endl;
	cout<<bst.floor('Y')<<endl;
	
	cout<<"Delete by Key 'Y':"<<endl;
	bst.deleteByKey('Y');
	bst.print_tree_graph();
	return 0;
}