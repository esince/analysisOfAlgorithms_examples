#include <bits/stdc++.h> 

using namespace std;

class Graph{
    int vertexNum;
    list<int> *adj;

    //will not be used in iterative approach
    // void DFScalc(int v, bool visited[]);
public:
    Graph(int v);
    void addEdge(int v, int w);
    void BFS(int v); //v is the starting vertex

};

Graph::Graph(int v){
    this->vertexNum = v;
    adj = new list<int>[v];
}
//func for adding edges to an directed graph
void Graph::addEdge(int edge1, int edge2){
    adj[edge1].push_back(edge2);
    
}

void Graph::BFS(int v){

    vector<bool> visited(vertexNum, false);

    list<int> queue;

    visited[v] = true;
    queue.push_back(v);

    //itr will get all adj vertices from a given vertex
    list<int>::iterator itr;
    while(!queue.empty()){
        v = queue.front();
        queue.pop_front();
        cout << v << " ";

        for(itr = adj[v].begin(); itr != adj[v].end(); ++itr){
            if(!visited[*itr]){
                visited[*itr] = true;
                queue.push_back(*itr);
            }
        }
    }

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

    for(int i = 0; i< 5; i++){
        cout <<  "starting from vertex " <<  i << ": ";
        g.BFS(i);
        cout << endl;
    }

    // Graph g(4); 
    // g.addEdge(0, 1); 
    // g.addEdge(0, 2); 
    // g.addEdge(1, 2); 
    // g.addEdge(2, 0); 
    // g.addEdge(2, 3); 
    // g.addEdge(3, 3); 
   
    // g.BFS(2); 
    

    return 0;
}