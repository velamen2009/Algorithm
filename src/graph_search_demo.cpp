#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <vector>

#include "../include/generic.h"
#include "../include/graph_search.h"

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
	//a is connected
	int a[] = {0, 1, 1, -1, -1, 1, 0, 1, -1, -1, -1, 0, 1, 1, -1, 0, 1, 1, 0, -1, 0};
	vector<int> vec(a, a+21);
	
	/*
	 * b[] = {
	 *			 0, -1,  1, -1, -1,  1
	 *			-1,  0, -1, -1, -1, -1
	 *			 1, -1,  0,  1,  1, -1
	 *          -1, -1,  1,  0,  1,  1
	 *          -1, -1,  1,  1,  0, -1
	 *			 1, -1, -1,  1, -1,  0 	
	 *        }
	 */
	//b is not connected
	int b[] = {0, -1, 1, -1, -1, 1, 0, -1, -1, -1, -1, 0, 1, 1, -1, 0, 1, 1, 0, -1, 0};
    vector<int> bvec(b, b+21);
	
	int source = rand()%6;
	
	Graph_AdjList g = Graph_AdjList(6, vec);
	g.print();
	
	Graph_Search gs = Graph_Search(g, source);
	gs.dfs();
	gs.bfs();
	
	Graph_AdjList gb = Graph_AdjList(6, bvec);
	gb.print();
	
	Graph_Search gsb = Graph_Search(gb, source);
	gsb.dfs();
	gsb.bfs();
	return 0;
} //

