#include <cstdlib>
#include <iostream>
#include <time.h>
#include "../include/redblacktree.h"

using namespace std;
using namespace alg;

int main(){
	RedBlackBST<char> rbt;
	srand(time(NULL));
	char a[] = {'A', 'C', 'E', 'H', 'L', 'M', 'P', 'R', 'S', 'X'};
	for(int i=0; i<10; ++i){
		//char key = rand()%26+65;
		rbt.put(a[i]);
		rbt.print_tree();
	}
	
	//cout<<bst.search('S')->lkey<<bst.search('S')->rkey<<endl;
	return 0;
}