#include <cstdlib>
#include <iostream>
#include <time.h>
#include "../include/binarysearchst.h"

using namespace std;
using namespace alg;


int main (int argc, char const *argv[]){
	BinarySearchST<char, int> st;
	srand(time(NULL));
	for(int i=0; i<1000; ++i){
		char key = rand()%26+65;
		st.put(key,1);
	}
	cout<<"The binary search symbol table:"<<endl;
	st.print();
	st.deletekey('A');
	cout<<"after delte:"<<endl;
	st.print();
	cout<<"The min key: "<<st.min()<<endl;
	cout<<"The max key: "<<st.max()<<endl;
	cout<<"Binary search: "<<endl;
	for(int i=0; i<10; ++i){
		char key = rand()%26+65;
		cout<<key<<" => "<<st.get(key)<<endl;
	}
	for(int i=0; i<10; ++i){
		char key = rand()%26+33;
		cout<<key<<" => "<<st.get(key)<<endl;
	}
	return 0;
}