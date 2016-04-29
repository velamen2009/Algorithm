#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <iostream>

#include "../include/generic.h"
#include "../include/bag.h"



int main()
{
	RANDOM_INIT();
	using namespace alg;
	using namespace std;

	srand(time(NULL));
	
	Bag<int> intBag;
	
    // generate random numbers and fill them to the stack
	for(int i = 0; i != 200; ++i ){
		intBag.add(rand()%100);
	}
	
	int count = intBag.size();
	int* a = intBag.collection();
	for(int i=0; i<count; ++i){
		if(0==i%10){ cout<<endl;}
		cout<<a[i]<<"\t";
	}
	return 0;
} //