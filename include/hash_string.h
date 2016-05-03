/*******************************************************************************         
 *
 * STRING HASH FUNCTIONS
 *
 * 1. http://en.wikipedia.org/wiki/Java_hashCode()
 * 2. http://www.isthe.com/chongo/tech/comp/fnv/
 * 2.1 http://www.isthe.com/chongo/tech/comp/fnv/#FNV-param
 * 2.2 https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
 ******************************************************************************/
 
#ifndef __STRING_HASH_H__
#define __STRING_HASH_H__

#include <stdint.h>

namespace alg{
	static uint32_t hash_string(const char * str, uint32_t len) {
		uint32_t hash = 0;
		for(uint32_t i=0; i<len; ++i){
			hash = 31*hash + (unsigned char)str[i];
		}
		return hash;
	}
	
	static unit32_t hash_fnv1a(const char * str, uint32_t len) {
		uint32_t prime  = 16777619U;
		uint32_t hash = 2166136261;
		for(uint32_t i=0; i<len; ++i){
			hash = hash^str[i];
			hash = hash*prime;
		}
		return hash;
	}
}
#endif