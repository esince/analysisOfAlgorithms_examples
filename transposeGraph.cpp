#include <bits/stdc++.h>

using namespace std;

//func for adding edges to an directed graph
void addEdge(vector<int> adj[], int edge1, int edge2){
    adj[edge1].push_back(edge2);
    
}

//func for transposing Graph
void transposeGraph(vector<int> adj[], vector<int> transpose[], int v){
    for(int i = 0; i < v; i++){
        for(int j = 0; j < adj[i].size(); j++){
            addEdge(transpose, adj[i][j], i);
        }
    }
}
 //func for printing graph by using adjacency list representation
void printGraph(vector<int> adj[], int v){
     for (int i = 0; i < v; i++) { 
        cout << endl << "Adjacency list of vertex " << i << endl << "head";
        
        for (int j = 0; j < adj[i].size(); j++){
            cout << " >> "<< adj[i][j];      
        } 
        cout << endl; 
    } 
}
int main(){
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 0, 3); 
    addEdge(adj, 2, 0); 
    addEdge(adj, 3, 2); 
    addEdge(adj, 4, 1); 
    addEdge(adj, 4, 3); 
  
   
    //tranpose has the same set of vertices 
    //with opposite direction compared to adj
    vector <int> transpose[V];
    transposeGraph(adj, transpose, V);

    printGraph(adj, V);
    printGraph(transpose, V);
    
    return 0;

}