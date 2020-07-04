#include <bits/stdc++.h> 

using namespace std;

// first insert all vertices into the stack
// then handle the head of the stack [which is the last node inserted] 
// thus the first node you handle is the last child.

// similar to BFS, 
// the only difference is queue is replaced by stack.
class Graph{
    int vertexNum;
    list<int> *adj;

    //will not be used in iterative approach
    // void DFScalc(int v, bool visited[]);
public:
    Graph(int v);
    void addEdge(int v, int w);
    void DFS(int v);
    void DFScalc(int u, vector<bool> &visited);

};

Graph::Graph(int v){
    this->vertexNum = v;
    adj = new list<int>[v];
}

//adding edges to a directed graph
void Graph::addEdge(int edge1, int edge2){
    adj[edge1].push_back(edge2);
}

void Graph::DFScalc(int u, vector<bool> &visited){
    
    stack<int> Stack;
    Stack.push(u);
    while(!Stack.empty()){
        u = Stack.top();
        Stack.pop();
        if(!visited[u]){
            cout << u << " ";
            visited[u] = true;
        }
        for(auto x = adj[u].begin(); x != adj[u].end(); ++x){
            if(!visited[*x]){
                Stack.push(*x);
            }
        }
    }
}

//prints only vertices that are reachable from a given vertex.
void Graph::DFS(int u){
    //every index of visited is initialized to false
    vector<bool> visited(vertexNum, false);
    for(int i= 0; i< vertexNum; i++){
        if(!visited[i]){
            DFScalc(i, visited);
        }
    }
}
int main(){
    Graph g(5);

    // g.addEdge(1, 0); 
    // g.addEdge(0, 2); 
    // g.addEdge(2, 1); 
    // g.addEdge(0, 3); 
    // g.addEdge(1, 4); 

    g.addEdge( 0, 1); 
    g.addEdge( 0, 4); 
    g.addEdge( 1, 2); 
    g.addEdge( 1, 3); 
    g.addEdge( 1, 4); 
    g.addEdge( 2, 3); 
    g.addEdge( 3, 4); 


    g.DFS(0);
    return 0;
}