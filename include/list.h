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
		listnode(T t){
			data = t;
			next = 0;
		}
	 };
	 
	 template<typename T>
	 class list {
		public:
			list():head(0),tail(0){}
			void push_front(T t){
				listnode<T>* node = new listnode<T>(t);
				if(0==head){
					head = node;
					tail = node;
				}
				else{
					node->next = head;
					head = node;
				}
			}
			void push_back(T t){
				listnode<T>* node = new listnode<T>(t);
				if(0==tail){
					head = node;
					tail = node;
				}
				else{
					tail->next = node;
					tail = node;
				}
			}
			T front(){
				return head->data;
			}
			T back(){
				return tail->data;
			}
			void pop_front(){
				if(0==head){return;}
				listnode<T>* node = head;
				head = head->next;
				delete node;
			}
			void pop_back(){
				if(0==tail){return;}
				if(head==tail){
					delete head;
					head = 0;
					tail = 0;
					return;
				}
				listnode<T>* node = tail;
				listnode<T>* p = head;
				while(p->next!=tail){
					p = p->next;
				}
				tail = p;
				tail->next = 0;
				delete node;
			}
			void print(){
				listnode<T>* p = head;
				while(p){
					std::cout<<p->data<<"\t";
					p = p->next;
				}
				std::cout<<"\n";
			}
		private:
			listnode<T>* search(T t){
				listnode<T>* p = head;
				while(p){
					if(p->data == t){
						return p;
					}
					p = p->next;
				}
				return 0;
			}
		private:
			listnode<T>* head;
			listnode<T>* tail;
	 };
}

#endif //