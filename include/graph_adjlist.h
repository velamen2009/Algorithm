/***********************************************************
 * DATA STRUCTURE OF GRAPH
 * ADJACENCY_LIST IMPLEMENTED WITH VECTOR
 **********************************************************/

#ifndef __GRAPH_ADJLIST_H__
#define __GRAPH_ADJLIST_H__

#include "generic.h"
#include <vector>

using namespace std;

namespace alg {
	class Graph_AdjList {
		
		public:
			struct Vertex{
				int id;
				bool visited;
				Vertex(int _id){
					id = _id;
					visited = false;
				}
			};
			/* _V:		number of vertices
			 * matrix:	the upper triangle matrix
			 *			a[i, i] = 0, self-edge weight = 0;
			 *			a[i, j] = -1, not connected
			 *			a[i, j] = 1, connected
			 *			matrix size is: n
			 *			a[i, j] = matrix[k], k = i*(n-(i+1)/2)+j when i<=j
			 *			a[i, j] = a[j, i] when i>j
			 */
			Graph_AdjList(int _V, vector<int> matrix):V(_V){
				for(int i=0; i<V; ++i){
					vertexList.push_back(new Vertex(i));
				}
				adj = new vector<Vertex*>[V];
				for(int i=0; i<V; ++i){
					adj[i] = vector<Vertex*>();
				}
				for(int row=0; row<V; ++row){
					for(int col=0; col<V; ++col){
						int k = 0;
						if(col>row){
							k = row*(2*V-row-1)/2+col;
							
						}
						else if(row > col){
							k = col*(2*V-col-1)/2+row;
						}
						else{
							continue;
						}
						if(1==matrix[k]){
							adj[row].push_back(vertexList[col]);
						}
					}
				}
			}
			void print(){
				vector<int> out(V*V, -1);
				
				cout<<"The adj graph is: "<<endl;
				for(int i=0; i<V; ++i){
					cout<<i<<":"<<"\t";
					int size = adj[i].size();
					for(int j=0; j<size; ++j){
						cout<<adj[i][j]->id<<"\t";
						int col = adj[i][j]->id;
						out[i*V+col] = 1;
					}
					cout<<endl;
				}
				cout<<endl;

				cout<<"The matrix graph is:"<<endl;
				for(int i=0; i<V; ++i){
					for(int j=0; j<V; ++j){
						if(i==j){
							cout<<"0"<<"\t";
						}
						else{
							cout<<out[i*V+j]<<"\t";
						}
					}
					cout<<endl;
				}
			}
			int vertex(){return V;}
			int edges(){return E;}

			
		private:
			int V; //num of vertices
			int E; //num of edges
			vector<Vertex*> vertexList;
			vector<Vertex*>* adj; //adjacency lists
	};
}

#endif //