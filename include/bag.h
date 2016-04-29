/***********************************************************
 * DATA STRUCTURE OF BAG
 **********************************************************/

#ifndef __BAG_H__
#define __BAG_H__

#include "generic.h"

namespace alg {
	/*
	 * The maximum size of bag
	 */
	const int size_step = 100;
	template<class T>
	class Bag {
		public:
			Bag():count(0),sz(size_step){
				data = new T[size_step];
			}
			void add(T t){
				if(1+count>=sz){
					resize();
				}
				data[count++]=t;
			}
			bool isEmpty(){return 0==count;}
			int size(){return count;}
			T* collection(){
				return data;
			}
		private:
			void resize(){
				T* a = new T[sz+size_step];
				for(int i=0; i<count; ++i){
					a[i] = data[i];
				}
				delete [] data;
				data = a;
			}
		private:
			T* data;
			int count;
			int sz;
	};
}

#endif //