#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//function for adding edge in an undirected graph
void addEdge(vector<int> adj[], int edge1, int edge2){
    adj[edge1].push_back(edge2);
    adj[edge2].push_back(edge1);
    
}

//func for printing graph
void printAdjList(vector<int> adj[], int VertexNum){
    
    for( int i = 0; i < VertexNum; i++){
        cout << "Adjacency list of vertex " << i  << endl << "head" ;
        for(auto x : adj[i])
            cout << " >> " << x;
        cout << endl;
    }
}

//driver code
int main(){

    int VertexNum = 5;
    vector<int> adj[VertexNum];

    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 

    printAdjList(adj, VertexNum);

    return 0;

}