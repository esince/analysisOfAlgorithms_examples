#include <bits/stdc++.h> 

using namespace std;

class Graph{
    int vertexNum;
    list<int> *adj;

    void DFScalc(int v, bool visited[]);
public:
    Graph(int v);
    void addEdge(int v, int w);
    void DFS(int v);

};

Graph::Graph(int v){
    this->vertexNum = v;
    adj = new list<int>[v];
}

//adding edges to a directed graph
void Graph::addEdge(int edge1, int edge2){
    adj[edge1].push_back(edge2);
}

void Graph::DFScalc(int v, bool visited[]){
    visited[v] = true; //starting vertex is marked as visited

    cout << v << " ";
    list<int>::iterator itr;
    for(itr = adj[v].begin(); itr!= adj[v].end(); itr++){
        if(!visited[*itr]){
            DFScalc(*itr, visited);
        }
    }
    
}

void Graph::DFS(int v){
    
    bool *visited = new bool[v];
    for(int i =0; i< v; i++){
        visited[i] = false; //make all vertices as not visited yet
    }
    //vector<bool> visited(v, false); //previously, it's done with that line
    DFScalc(v, visited);
}

int main(){

    Graph g(5);
    g.addEdge( 0, 1); 
    g.addEdge( 0, 4); 
    g.addEdge( 1, 2); 
    g.addEdge( 1, 3); 
    g.addEdge( 1, 4); 
    g.addEdge( 2, 3); 
    g.addEdge( 3, 4); 

    g.DFS(0);
    // g.DFS(1);
    // g.DFS(2);
    // g.DFS(3);
    return 0;
}