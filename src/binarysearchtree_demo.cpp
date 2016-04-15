#include <cstdlib>
#include <iostream>
#include <time.h>
#include "../include/binarysearchtree.h"

using namespace std;
using namespace alg;

int main(){
	BinarySearchTree<char, int> bst;
	srand(time(NULL));
	for(int i=0; i<1000; ++i){
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
	
	cout<<"The floor of 'C' is:"<<endl;
	cout<<bst.floor('C')<<endl;
	return 0;
}