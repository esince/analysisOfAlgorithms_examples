#include <bits/stdc++.h>

using namespace std;

class Graph{
    int vertexNum;
    list<int> *adj;

public:
    Graph(int v);
    void addEdge(int x, int y, bool z);
    int DFS(int source);

};

Graph::Graph(int v){
    vertexNum = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int edge1, int edge2, bool bidir){
    adj[edge1].push_back(edge2);
    if(bidir){
        adj[edge1].push_back(edge2);
    }
}

//function for performing DFS on each vertex
int Graph::DFS(int source){
    map<int, bool> visited; // map is used to mark visited/unvisited vertices
    vector<int> dependent; //array that contains dependent vertices of one vertex
    int count = 0; 

    stack<int> Stack;

    Stack.push(source); //source vertex is pushed to stack
    visited[source] = true;

    //traverse through the vertices until the stack is empty
    while(!Stack.empty()){
        int top = Stack.top(); // top stores source vertex. 
        Stack.pop();

        //for the each vertices adjacent to source vertex
        for(auto i: adj[top]){
            if(visited[i] == false){
                dependent.push_back(i);
                count++;
                visited[i] = true;

                Stack.push(i); //current vertex to stack
            }
        }
    }
    if(count == 0){
        cout << "Vertex " << source
                 << " is not dependent on any vertex.\n"; 
            return count; 
    }

    cout << "Vertex " << source<< " dependency "; 
    for(auto i : dependent){
        cout <<" >> " << i;
    }
    cout << endl;

    return count;
}

void operations(int arr[][2], int n, int m){
    Graph graph(n);

    for(int i = 0; i < m; i++){
        graph.addEdge(arr[i][0], arr[i][1], false);
    }

    int min = INT_MAX;
    int node = 0;

    for(int i = 0; i < n; i++){
        int count = graph.DFS(i);

        if(count < min){
            min = count;
            node = i;
        }
    }
    cout << "Node " << node 
         << " has minimum dependency of "
         << min; 
}
int main(){

    int n = 6, m = 6;

    int arr[][2]= { { 0, 1 }, 
                     { 0, 2 }, 
                     { 2, 3 }, 
                     { 4, 5 }, 
                     { 3, 4 }, 
                     { 1, 5 } }; 

    // int n = 3, m = 3;

    // int arr[][2]= { { 0, 1 }, 
    //                 { 1, 2 }, 
    //                 { 2, 0 } }; 
  
  
    operations(arr, n, m); 
    return 0;
}