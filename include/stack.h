/***********************************************************
 * DATA STRUCTURE OF STACK
 * FILO
 **********************************************************/

#ifndef __CSTACK_H__
#define __CSTACK_H__

#include "generic.h"

namespace alg {
	/*
	 * The maximum size of stack
	 */
	const int max_size = 100;
	template<class T>
	class Stack {
		public:
			Stack():top(-1){}
			void push(T t){
				if(max_size-1==top)
				{
					return;
				}
				data[++top] = t;
			}
			
			T pop(){
				return data[top--];
			}
			
			void print() {
			for(int i=0; i<= top; ++i) {
				std::cout<<data[i]<<"\t";
			}
			std::cout<<"\n"<<std::endl;
		}
		private:
			T data[max_size];
			int top;
	};
}

#endif //