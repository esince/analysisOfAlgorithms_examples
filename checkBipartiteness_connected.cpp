// algorithm:
// 1. RED color to the source (putt into set U).
// 2. BLUE color to all the neighbor's of s (putt into set V).
// 3. Color all neighbor’s neighbor with RED color (putting into set U).
// 4. assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2.
// 5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite)


//example for connected graphs

#include <bits/stdc++.h>
#define V 4
// #define V 5

using namespace std;

//returns true if G[V][V] is bipartite
bool isBipartite(int G[][V], int s){
    int colorArr[V]; //-1: no color, 0: blue, 1: red
    //initialization of colorArr[]
    for(int i = 0; i< V; i++){
        colorArr[i] = -1;
    }
    //source vertex -> red
    colorArr[s] = 1;

    //use queue for bfs traversal
    queue <int> q;
    q.push(s);

    while(!q.empty()){
        int top = q.front();
        q.pop();

        //1: red
        //if there is a self loop
        if(G[top][top] == 1)
            return false;

        for(int x  = 0; x < V; ++x){
            if(colorArr[x] == -1 && G[top][x]){
                colorArr[x] = 1 - colorArr[top];
                q.push(x);
            }
            else if( colorArr[x] == colorArr[top] && G[top][x]){
                return false;
            }
        }

    }
    return true;

}

//driver code
int main(){

//if number of vertices is odd in a cylce, then this is not bipartite 
// 0-1-2-3-4-0 cyclic graph
    // int graph[][V] = {{0,1,0,1,1},
    //                    {1,0,1,0,0},
    //                    {0,1,0,1,0},
    //                    {1,0,1,0,1},
    //                    {1,0,0,1,0}};

//if a node have an edge to itself. it violates being bipartite
//in this example, in the 4th node there is a self loop.
    // int graph[][V] = {{0,1,0,1},
    //                    {1,0,1,0},
    //                    {0,1,0,1},
    //                    {1,0,1,1}};

//if number of vertices is even in a cycle, then this is bipartite. 
    int graph[][V] = {{0,1,0,1},
                       {1,0,1,0},
                       {0,1,0,1},
                       {1,0,1,0}};
    isBipartite(graph, 0) ? cout << "Yes" : cout << "No"; 
    
    return 0;
}