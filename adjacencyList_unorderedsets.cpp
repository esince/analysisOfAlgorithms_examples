#include <bits/stdc++.h>

using namespace std;

//in this example, edges are not stored in any order. 

class Graph{
public:
    int VertexNum;
    unordered_set<int> *adj;
};

Graph *createGraph(int V){

    Graph *graph = new Graph;
    graph->VertexNum = V;
    graph->adj = new unordered_set<int>[V];

    return graph;
}

//takes O(1)
void addEdge(Graph *graph, int edge1, int edge2){
    graph->adj[edge1].insert(edge2);
    graph->adj[edge2].insert(edge1);
}

void printGraph(Graph *graph){
    for (int i = 0; i < graph->VertexNum; i++){
        unordered_set<int> start = graph->adj[i];
        cout << endl << "Adjacency list of vertex " << i 
             << endl << "Head";
        for (auto itr = start.begin(); itr != start.end(); itr++){
            cout << " >> "<< *itr << " ";
        }
        cout << endl << endl;
    }
}

//takes O(1)
void searchEdge(Graph *graph, int edge1, int edge2){
    auto itr = graph->adj[edge1].find(edge2);
    if (itr == graph->adj[edge1].end())
        cout << "Edge from " << edge1 << " to " << edge2 << " not found.";
    else
        cout << "Edge from " << edge1 << " to " << edge2 << " found.";
    cout << endl;      
}
int main(){
    int V = 5;
    Graph *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    searchEdge(graph, 1,3);

    return 0;
}