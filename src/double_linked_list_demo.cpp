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
	cout<<"The size of double linked list is: "<<charDList.size()<<endl;
	
	for(int i = 0; i != 10; ++i ){
		charDList.insertTail(rand()%26+65);
	}
	cout<<"Initial 10 times insert at tail:"<<endl;
	cout<<"The size of double linked list is: "<<charDList.size()<<endl;
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
	
	DoublyLinkedList<char>::iterator it = charDList.begin();
	cout<<"The begin is: "<<it->data<<endl;
	
	DoublyLinkedList<char>::iterator rit = charDList.end();
	cout<<"The end is: "<<rit->data<<endl;
	
	for(int i=0; i<3; ++i){
		cout<<"The value "<<i<<" is: "<<charDList[i]->data<<endl;
	}
	return 0;
} //