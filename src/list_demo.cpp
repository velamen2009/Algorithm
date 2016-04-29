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
	
	const int MAX_ELEMENTS = 5;
	list<int> intlist;
	
	for(int i = 0; i != MAX_ELEMENTS; ++i ){
		int a = rand()%100;
		intlist.push_back(a);
		intlist.push_front(a);
	}
	
	std::cout<<"List after push back and front:"<<std::endl;
	intlist.print();

	for(int i = 0; i != 3; ++i ){
		intlist.pop_back();
		intlist.pop_front();
	}
	std::cout<<"List after pop back and front:"<<std::endl;
	intlist.print();
	
	return 0;
} //