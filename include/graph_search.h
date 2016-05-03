/***********************************************************
 * DFS AND BFS OF GRAPH
 **********************************************************/

#ifndef __GRAPH_SEARCH_H__
#define __GRAPH_SEARCH_H__

#include "generic.h"
#include "graph_adjlist.h"
#include <vector>
#include <queue>
#include <string>

using namespace std;

namespace alg {
class Graph_Search{
public:
	Graph_Search(const Graph_AdjList& g, int s){
		source = s;
		G = g;
		visited = new bool[G.vertex()];
		init();
	}
	
	void dfs(){
		init();
		cout<<"Starting DFS:"<<endl;
		dfs(source);
		cout<<endl;
		cout<<"Totally "<<count<<" vertices are connected."<<endl;
		cout<<"Total vertices count is: "<<G.vertex()<<endl;
		string s = count == G.vertex()?"Graph is connected!" : "Graph is not connected!";
		cout<<s<<endl;
	}
	
	void bfs(){
		init();
		cout<<"Starting BFS:"<<endl;
		queue<int> q;
		q.push(source);
		++count;
		visited[source] = true;
		while(!q.empty()){
			int v = q.front();
			cout<<v<<"->";
			q.pop();
			vector<Vertex*> t = G.adj[v];
			for(int i=0; i<t.size(); ++i){
				if(!visited[t[i]->id]){
					visited[t[i]->id] = true;
					q.push(t[i]->id);
					++count;
				}
			}
		}
		cout<<endl;
		cout<<"Totally "<<count<<" vertices are connected."<<endl;
		cout<<"Total vertices count is: "<<G.vertex()<<endl;
		string s = count == G.vertex()?"Graph is connected!" : "Graph is not connected!";
		cout<<s<<endl;
	}

private:
	void init(){
		count = 0;
		for(int i=0; i<G.vertex(); ++i){
			visited[i] = false;
		}
	}
	void dfs(int v){
		++count;
		visited[v] = true;
		cout<<v<<"->";
		vector<Vertex*> t = G.adj[v];
		for(int i=0; i<t.size(); ++i){
			if(!visited[t[i]->id]){
				dfs(t[i]->id);
			}
		}
	}
private:
	bool *visited;
	int *path;
	int count;
	int source;
	Graph_AdjList G;
};

}

#endif