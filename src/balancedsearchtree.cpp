#include <cstdlib>
#include <iostream>
#include <time.h>
#include "../include/balancedsearchtree.h"

using namespace std;
using namespace alg;

int main(){
	BalancedSearchTree<char, int> bst;
	srand(time(NULL));
	for(int i=0; i<2; ++i){
		char key = rand()%26+65;
		bst.put(key, i);
	}
	cout<<"The balanced search tree:"<<endl;
	bst.print_tree23();
	return 0;
}