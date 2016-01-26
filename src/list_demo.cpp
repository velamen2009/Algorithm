#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include "../include/generic.h"
#include "../include/list.h"

int main()
{
	RANDOM_INIT();
	using namespace alg;

	srand(time(NULL));
	
	//decare int stack
	const int MAX_ELEMENTS = 10;
	list<int> intlist;
	
    // generate random numbers and fill them to the stack
	for(int i = 0; i != MAX_ELEMENTS; ++i ){
		intlist.add(rand()%100);
	}
	
	//print stack
	std::cout<<std::endl;
	intlist.print();
	std::cout<<std::endl;

	return 0;
} //