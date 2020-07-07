#include <bits/stdc++.h>

using namespace std;

// DFS is used for detecting cycles
// time complexity O(V+E) --same as time complexity of DFS traversal
// space complexity O(V) -- a space for stack is needed. 

// cycle is found when there is a back edge

class Graph{
    int vertexNum; //Number of vertices
    list<int> *adj; //pointer to an array that contains adjacency lists
    bool isCycliccalc(int v, bool vis[], bool *rs); // will be used by isCyclic()
                                                    //recursive helper function 
                                                    //to detect cycle in different DFS trees
public:
    Graph(int V);
    void addEdge(int edge1, int edge2);
    bool isCyclic();

};

Graph::Graph(int v){
    vertexNum  = v;
    adj = new list<int>[v];  //dynamic memory allocation for adj list
}
void Graph::addEdge(int edge1, int edge2){
    adj[edge1].push_back(edge2); //add edge2 to edge1's list. 
}
bool Graph::isCycliccalc(int v, bool visited[], bool *recStack){
    if(visited[v] == false){
        visited[v] = true; // mark the current vertex as visited
        recStack[v] = true; //also, mark the vertex in recursion stack

        list<int>::iterator itr; //will be traversed all the vertices adjacent to current vertex.
        for(itr = adj[v].begin(); itr != adj[v].end(); ++itr){
            //recursively call the isCycliccalc() for all adjacent vertices for the current vertex
            if(visited[*itr] == false && isCycliccalc(*itr, visited, recStack))
                return true;
            else if(recStack[*itr] == true)
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

//func for calling recursive function for all the vertices. 
bool Graph::isCyclic(){
    bool *visited = new bool[vertexNum]; // allocate a new bool array pointer
    bool *recStack = new bool[vertexNum];

    for(int i = 0; i < vertexNum; i++){
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 0; i < vertexNum; i++){
        if(isCycliccalc(i, visited, recStack))
            return true;
    }

    return false;
}

//driver code
int main(){

    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    // g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    // g.addEdge(3, 3); 
  
    if(g.isCyclic()) 
        cout << "Cycle detected"; 
    else
        cout << "Any cycle detected"; 
        
    return 0;
}