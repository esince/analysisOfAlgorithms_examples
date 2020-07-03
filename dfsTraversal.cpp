#include <bits/stdc++.h> 

using namespace std;

//func for adding edges to an undirected graph
void addEdge(vector<int> adj[], int edge1, int edge2){
    adj[edge1].push_back(edge2);
    adj[edge2].push_back(edge1);
}

//a recursive func to do depth first search of graph, from a vertex u
void DFScalc(vector<int> adj[], int u, vector<bool> &visited){
    visited[u] = true;
    cout << u << " ";
    for(int i = 0; i < adj[u].size(); i++){
        if(visited[adj[u][i]] == false)
            DFScalc(adj, adj[u][i], visited);
    }
}

//calls DFScalc() function for all unvisited vertices
void DFS(vector<int> adj[], int v){
    //every index of visited is initialized to false
    vector<bool> visited(v, false);

    for(int i = 0; i< v; i++){
        //it's crucial to check if the vertex is visited before
        if(visited[i] == false){
            DFScalc(adj, i, visited);
        }
    }
}

int main(){

    int v = 5;

    vector<int> *adj = new vector<int>[v]; 
    // vector<int> adj[v];

    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 

    DFS(adj, v);

    return 0;
}