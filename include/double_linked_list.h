/*******************************************************************************
 * DOUBLE LINKED-LIST FROM LINUX KERNEL
 *
 * http://en.wikipedia.org/wiki/Double_linked_list
 ******************************************************************************/

#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

#include <iostream>

using namespace std;

namespace alg{
	template<typename T>
	struct DoublyLinkedNode{
		DoublyLinkedNode<T>* prev;
		DoublyLinkedNode<T>* next;
		T data;
		DoublyLinkedNode(T t){
			prev = 0;
			next = 0;
			data = t;
		}
	};
	
	template<typename T>
	class DoublyLinkedList{
	public:
		DoublyLinkedList():head(0),tail(0){}
		bool empty(){return 0==head;}
		int size(){
			DoublyLinkedNode<T>* node = head;
			int size = 0;
			while(node!=0){
				node=node->next;
				++size;
			}
			return size;
		}
		void insertAfter(T u, T v){
			DoublyLinkedNode<T>* node = searchNode(u);
			if(NULL==node){
				return;
			}
			insertAfter(node, new DoublyLinkedNode<T>(v));
		}
		void insertBefore(T u, T v){
			DoublyLinkedNode<T>* node = searchNode(u);
			if(NULL==node){
				return;
			}
			insertBefore(node, new DoublyLinkedNode<T>(v));
		}
		void insertHead(T t){
			insertHead(new DoublyLinkedNode<T>(t));
		}
		void insertTail(T t){
			insertTail(new DoublyLinkedNode<T>(t));
		}
		void remove(T t){
			DoublyLinkedNode<T>* node = searchNode(t);
			remove(node);
		}
		void removeHead(){
			remove(head);
		}
		void removeTail(){
			remove(tail);
		}
		void print(){
			DoublyLinkedNode<T>* p = head;
			while(NULL!=p){
				cout<<p->data<<"\t";
				p=p->next;
			}
			cout<<endl;
		}
		void print_reverse(){
			DoublyLinkedNode<T>* p = tail;
			while(NULL!=p){
				cout<<p->data<<"\t";
				p=p->prev;
			}
			cout<<endl;
		}
		typedef DoublyLinkedNode<T>* iterator;
		iterator begin(){return head;}
		iterator end(){return tail;}
		iterator operator[](int index){
			if(0==index){return head;}
			int i=0;
			iterator t = head;
			while(++i<=index){
				t = t->next;
			}
			return t;
		}
		
	public:
		DoublyLinkedNode<T>* searchNode(T t){
			DoublyLinkedNode<T>* p = head;
			while(NULL!=p){
				if(t==p->data){
					return p;
				}
				p=p->next;
			}
			return 0;
		}
		void insertAfter(DoublyLinkedNode<T>* node, DoublyLinkedNode<T>* newNode){
			newNode->prev = node;
			newNode->next = node->next;
			if(0==node->next){
				tail = newNode;
			}
			else{
				node->next->prev = newNode;
			}
			node->next = newNode;
		}
		void insertBefore(DoublyLinkedNode<T>* node, DoublyLinkedNode<T>* newNode){
			newNode->prev = node->prev;
			newNode->next = node;
			if(0==node->prev){
				head = newNode;
			}
			else{
				node->prev->next = newNode;
			}
			node->prev = newNode;
		}
		void insertHead(DoublyLinkedNode<T>* newNode){
			if(0==head){
				head = newNode;
				tail = newNode;
			}
			else{
				insertBefore(head, newNode);
			}
		}
		void insertTail(DoublyLinkedNode<T>* newNode){
			if(0==tail){
				head = newNode;
				tail = newNode;
			}
			else{
				insertAfter(tail, newNode);
			}
		}
		void remove(DoublyLinkedNode<T>* node){
			if(NULL==node){return;}
			if(0==node->prev){
				head = node->next;
			}
			else{
				node->prev->next = node->next;
			}
			if(0==node->next){
				tail = node->prev;
			}
			else{
				node->next->prev = node->prev;
			}
			delete node;
		}
	private:
		DoublyLinkedNode<T>* head;
		DoublyLinkedNode<T>* tail;
	};
}
#endif

