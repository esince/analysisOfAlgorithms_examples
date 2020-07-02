#include <bits/stdc++.h>

using namespace std;

// Basic functions associated with Set:

// begin() – Returns an iterator to the first element in the set.
// end() – Returns an iterator to the theoretical element that follows last element in the set.
// size() – Returns the number of elements in the set.
// max_size() – Returns the maximum number of elements that the set can hold.
// empty() – Returns whether the set is empty.

class Graph{
    public: 
    int VertexNum;
    set<int, greater<int>> *adj;
};

//func for creating a graph of V vertices by using sets
Graph* createGraph(int V){
    Graph *graph = new Graph;
    graph->VertexNum = V;
    graph->adj = new set<int, greater<int>>[V];
    
    return graph; //a pointer of type Graph class is returned.
}

//adding edges to an undirected graph
//takes O(logV)
void addEdge(Graph* graph, int edge1, int edge2){
    graph->adj[edge1].insert(edge2);
    graph->adj[edge2].insert(edge1);    
}

//function for printing graph. 
void printGraph(Graph* graph){
    for(int i= 0; i< graph->VertexNum; i++){
        set<int, greater<int> > start = graph->adj[i];
        cout << endl << "Adjacency list of vertex " << i << endl << "head";

        for(auto itr = start.begin(); itr!= start.end(); itr++){
            cout << " >> "<< *itr;

        }
        cout << endl;
    }
}
//takes in O(logV)
void searchEdge(Graph* graph, int edge1, int edge2){
    auto itr = graph->adj[edge1].find(edge2);
    cout << endl;
    if(itr == graph->adj[edge1].end()){
        cout << "Edge from " << edge1 << " to " << edge2 << " not found." << endl;
    }
    else{
        cout << "Edge from " << edge1 << " to " << edge2 << " found." << endl;
    }
    
}

int main(){
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
    printGraph(graph);

    searchEdge(graph, 2,1 );
}