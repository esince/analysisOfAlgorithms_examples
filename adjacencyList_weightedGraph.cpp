#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<pair<int, int>> adj [], int edge1, int edge2, int w){
    //weight should be integer, otherwise implicit conversion from pair<int,double>
    adj[edge1].push_back(make_pair(edge2, w));
    adj[edge2].push_back(make_pair(edge1, w));
}

void printGraph(vector <pair <int,int>> adj[], int V){
    int v, w;
    for(int i= 0; i < V; i++){
        cout << i << " is connected with" << endl;
        for(auto itr = adj[i].begin(); itr != adj[i].end(); itr++){
            //first and second elements in a pair
            v = itr->first;
            w = itr->second;
            cout << endl << v << ", edge weight = " << w << endl;
        }
        cout << endl;
    }
}


int main(){
    int V = 5; //vertex number

    //pair holds the edge connected to our edge with a w weight
    vector<pair<int,int>> adj[V];

    addEdge(adj, 0, 1, 10); 
    addEdge(adj, 0, 4, 20); 
    addEdge(adj, 1, 2, 30); 
    addEdge(adj, 1, 3, 40); 
    addEdge(adj, 1, 4, 50); 
    addEdge(adj, 2, 3, 60); 
    addEdge(adj, 3, 4, 70);

    printGraph(adj, V); 
    
    return 0;
}