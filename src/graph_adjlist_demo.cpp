#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <vector>

#include "../include/generic.h"
#include "../include/graph_adjlist.h"

using namespace std;

int main()
{
	RANDOM_INIT();
	using namespace alg;

	srand(time(NULL));
	
	/*
	 * a[] = {
	 *			 0,  1,  1, -1, -1,  1
	 *			 1,  0,  1, -1, -1, -1
	 *			 1,  1,  0,  1,  1, -1
	 *          -1, -1,  1,  0,  1,  1
	 *          -1, -1,  1,  1,  0, -1
	 *			 1, -1, -1,  1, -1,  0 	
	 *        }
	 */
	int a[] = {0, 1, 1, -1, -1, 1, 0, 1, -1, -1, -1, 0, 1, 1, -1, 0, 1, 1, 0, -1, 0};
    vector<int> vec(a, a+21);
	
	Graph_AdjList g = Graph_AdjList(6, vec);
	g.print();
	return 0;
} //