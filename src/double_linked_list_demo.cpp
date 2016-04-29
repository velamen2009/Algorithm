#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include "../include/generic.h"
#include "../include/double_linked_list.h"

int main()
{
	RANDOM_INIT();
	using namespace alg;
	using namespace std;

	srand(time(NULL));
	
	DoublyLinkedList<char> charDList;
	
	for(int i = 0; i != 10; ++i ){
		charDList.insertTail(rand()%26+65);
	}
	cout<<"Initial 10 times insert at tail:"<<endl;
	charDList.print();
	
	cout<<"3 times insert at head:"<<endl;
	char c = rand()%26+65;
	charDList.insertHead(c);
	charDList.insertHead(c);
	charDList.insertHead(c);
	charDList.print();
	
	cout<<"Insert before and after:"<<endl;
	char d = (c+1-65)%26+65;
	char e = (d+1-65)%26+65;
	charDList.insertAfter(c, d);
	charDList.insertBefore(d, e);
	charDList.print();
	
	cout<<"Remove:"<<endl;
	charDList.remove(e);
	charDList.remove(d);
	charDList.print();
	
	cout<<"Remove head and tail:"<<endl;
	charDList.removeHead();
	charDList.removeTail();
	charDList.print();
	
	cout<<"Reverse order:"<<endl;
	charDList.print_reverse();
	
	return 0;
} //