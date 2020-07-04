#include<bits/stdc++.h>

using namespace std;

void BFS(int currentVertex, int vertexNum, vector<bool> visited, 
            vector<int> dp, vector<int> v, vector <vector<int>> &adj ){
    while(currentVertex <= vertexNum){
        int node = v[currentVertex - 1];
        cout << node << ", ";

        for(int i = 0; i< adj[node].size();i++){
            int next = adj[node][i];

            if((!visited[next]) && (dp[next] < dp[node] + 1)){
                v.push_back(next);

                dp[next] = dp[node] + 1;

                visited[next] = true;
            }
        }
        currentVertex++;
    }
}
void BFSTraversal(vector<vector<int>> adj, int vertexNum, int s){
    //all nodes are marked as unvisited.
    vector<bool> visited(vertexNum + 1, false);

    //distance array is initialized by 0.
    vector<int> dp(vertexNum+1, 0), v;

    v.push_back(s);
    // dp = 0;
    visited[s] = true;
    BFS(2, vertexNum, visited, dp, v, adj);
}

void addEdge(vector<vector<int>> adj, int edge1, int edge2){
    adj[edge1].push_back(edge2);
}

int main(){
    // int v = 4;

    // vector<vector<int>> adj(v+1);

    // addEdge(adj, 0, 1); 
    // addEdge(adj, 0, 2); 
    // addEdge(adj, 1, 2); 
    // addEdge(adj, 2, 0);  
    // addEdge(adj, 2, 3); 
    // addEdge(adj, 3, 3); 

    
    
    // // addEdge(adj, 0, 1); 
    // // addEdge(adj, 0, 4); 
    // // addEdge(adj, 1, 2); 
    // // addEdge(adj, 1, 3); 
    // // addEdge(adj, 1, 4); 
    // // addEdge(adj, 2, 3); 
    // // addEdge(adj, 3, 4); 

    // BFSTraversal(adj, v, 2);

    int N = 4; 
  
    // Creating adjacency list 
    // for representing graph 
    vector<vector<int> > adj(N + 1); 
    adj[0].push_back(1); 
    adj[0].push_back(2); 
    adj[1].push_back(2); 
    adj[2].push_back(0); 
    adj[2].push_back(3); 
    adj[3].push_back(3); 
  
    // Following is BFS Traversal 
    // starting from vertex 2 
    BFSTraversal(adj, N, 2); 

    return 0;
}