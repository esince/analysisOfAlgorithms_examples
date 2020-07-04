#include<iostream> 
#include <list> 
#include <stack> 

using namespace std;

//time complexity is O(V+E)
//O(V) - auxiliary space, becase stack is used

//vector can be used instead of stack.
// If the vector is used 
//then print the elements in reverse order to get the topological sorting

class Graph{
    int vertexNum;
    list<int> *adj;

    void topologicalSortcalc(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int v);
    void addEdge(int edge1, int edge2);
    void topologicalSort();

};

Graph::Graph(int v){
    this->vertexNum = v;
    adj = new list<int>[v];
}

//adding edges to a directed graph
void Graph::addEdge(int edge1, int edge2){
    adj[edge1].push_back(edge2);
}

void Graph::topologicalSortcalc(int v, bool visited[], stack<int> &Stack){
    visited[v] = true;

    list<int>::iterator itr;
    for(itr = adj[v].begin(); itr != adj[v].end(); ++itr){
        if(!visited[*itr])
            topologicalSortcalc(*itr, visited,Stack);
    }
    Stack.push(v);

}

void Graph::topologicalSort(){
    stack<int> Stack;

    bool *visited = new bool[vertexNum];
    for(int i = 0; i< vertexNum; i++){
        visited[i] = false;
    }
    for(int i = 0; i< vertexNum; i++){
        //it's crucial to check if the vertex is visited before
        if(visited[i] == false){
            topologicalSortcalc(i, visited, Stack);
        }
    }
    while(Stack.empty() == false){
        cout << Stack.top(); 
        Stack.pop();
    }

}
int main(){
    // Graph g(6); 

    // g.addEdge(5, 2); 
    // g.addEdge(5, 0); 
    // g.addEdge(4, 0); 
    // g.addEdge(4, 1); 
    // g.addEdge(2, 3); 
    // g.addEdge(3, 1); 

    Graph g(5);
    g.addEdge( 0, 1); 
    g.addEdge( 0, 4); 
    g.addEdge( 1, 2); 
    g.addEdge( 1, 3); 
    g.addEdge( 1, 4); 
    g.addEdge( 2, 3); 
    g.addEdge( 3, 4); 

    g.topologicalSort(); 

    return 0;

}