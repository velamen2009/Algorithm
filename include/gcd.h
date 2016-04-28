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
	static T gcd_minus(T u, T v){
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
	
	/*
	 * get the greatest common divisor for two elements
	 */
	template<typename T>
	static T gcd_division(T u, T v){
		T c;
		while(v!=0){
			c=u%v;
			u=v;
			v=c;
		}
		return u;
	}
	
	/*
	 * get the least common multiple for two elements
	 */
	template<typename T>
	static T gcm_minus(T u, T v){
		T a(u);
		T b(v);
		T t(u);
		while(u > 0){
			if(u < v){
				t = u;
				u = v;
				v = t;
			}
			u = u - v;
		}
		return a*b/v;
	}
	
	/*
	 * get the least common multiple for two elements
	 */
	template<typename T>
	static T gcm_division(T u, T v){
		T a(u);
		T b(v);
		T c;
		while(v!=0){
			c=u%v;
			u=v;
			v=c;
		}
		return a*b/u;
	}
}

#endif	//