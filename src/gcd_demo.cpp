#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include "../include/generic.h"
#include "../include/gcd.h"

int main()
{
	RANDOM_INIT();
	using namespace alg;
	const int MAX_ELEMENTS = 10;
	int list[MAX_ELEMENTS];

	srand(time(NULL));
	// generate random numbers and fill them to the list
	for(int i = 0; i < MAX_ELEMENTS; i++ ){
		list[i] = rand()%100+1;
	}
	printf("The list is:\n");
	printlist(list,MAX_ELEMENTS);
	// get gcd for each pair of data
	for(int i=0; i!=MAX_ELEMENTS/2; ++i){
		std::cout<<list[2*i]<<"\t"<<list[2*i+1]<<"\t"<<gcd_minus(list[2*i],list[2*i+1])<<"\t"<<gcd_division(list[2*i],list[2*i+1])<<"\t"<<gcm_minus(list[2*i],list[2*i+1])<<"\t"<<gcm_division(list[2*i],list[2*i+1])<<"\n";
	}
	std::cout<<std::endl;
	return 0;
}