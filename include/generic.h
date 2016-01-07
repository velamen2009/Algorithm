/*************************************************************
*
* GENERIC METHODS FOR ALGORITHM
*
**************************************************************/

#ifndef __ALG_INC_H__
#define __ALG_INC_H__

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)

#define RANDOM_INIT()	srand(time(NULL))
#define RANDOM(L, R)	(L + rand()%((R) - (L) + 1))

namespace alg {
	/**
	 * swap of 2-elements, original value
	 */
	template<typename T>
	static inline void swap(T& v1, T& v2){
		T _t(v1);
		v1 = v2;
		v2 = _t;
	}
	
	/**
	 * print out the elements in array with length n
	 */
	template<typename T>
	static void printlist(T& list, int n){
		for(int i=0; i!=n; ++i){
			std::cout<<list[i]<<"\t";
		}
		std::cout<<"\n"<<std::endl;
	}
}

#endif
