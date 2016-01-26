/***********************************************************
 * Implementation of List
 **********************************************************/
 
#ifndef __CLIST_H__
#define __CLIST_H__

#include "generic.h"

namespace alg {
	/*
	 * list node 
	 */
	 template<typename T>
	 struct listnode {
		T data;
		listnode<T>* next;
	 };
	 
	 template<typename T>
	 class list {
		public:
			list():head(NULL),tail(NULL),size(0){}
			void add(T t){
				if(NULL==head){
					head = new listnode<T>;
					tail = head;
				}
				listnode<T>* temp = new listnode<T>;
				temp->data = t;
				temp->next = NULL;
				tail->next = temp;
				tail = temp;
			} 
			void print(){
				listnode<T>* temp = head->next;
				while(temp){
					std::cout<<temp->data<<"\t";
					temp = temp->next;
				}
				std::cout<<"\n";
			}
		private:
			listnode<T>* head;
			listnode<T>* tail;
			int size;
	 };
}

#endif //