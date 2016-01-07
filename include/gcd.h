/***********************************************************
 * GET THE　MAXIMUM COMMON DIVISOR OF TWO ELEMENT
 **********************************************************/

#ifndef __GREATEST_COMMON_DIVISOR_H__
#define __GREATEST_COMMON_DIVISOR_H__

#include "generic.h"

namespace alg {
	/*
	 * get the greatest common divisor for two elements
	 */
	template<typename T>
	static T gcd(T u, T v){
		T t(u);
		while(u > 0){
			if(u < v){
				t = u;
				u = v;
				v = t;
			}
			u = u - v;
		}
		return v;
	}
}

#endif	//