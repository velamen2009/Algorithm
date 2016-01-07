#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include "../include/generic.h"
#include "../include/stack.h"

int main()
{
	RANDOM_INIT();
	using namespace alg;

	srand(time(NULL));
	
	//decare int stack
	const int MAX_ELEMENTS = 10;
	Stack<int> intStack;
	
    // generate random numbers and fill them to the stack
	for(int i = 0; i != MAX_ELEMENTS; ++i ){
		intStack.push(rand()%100);
	}
	
	//print stack
	std::cout<<std::endl;
	intStack.print();
	std::cout<<std::endl;
	
	//pop stack
	for(int i=0; i!=MAX_ELEMENTS/2; ++i) {
		intStack.pop();
	}
	
	//print stack
	std::cout<<std::endl;
	intStack.print();
	std::cout<<std::endl;
	return 0;
} //