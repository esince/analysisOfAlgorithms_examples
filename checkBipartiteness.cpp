// algorithm:
// 1. RED color to the source (putt into set U).
// 2. BLUE color to all the neighbor's of s (putt into set V).
// 3. Color all neighbor’s neighbor with RED color (putting into set U).
// 4. assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2.
// 5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored with 2 vertices (or graph is not Bipartite)

#include <bits/stdc++.h>
#define V 4

using namespace std;

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
        if(G[top][top] == 1)
            return false;
        for(int x  = 0; x < V; ++x){
            if(colorArr[x] == -1 && G[top][x]){
                colorArr[x] = 1 - colorArr[top];
                q.push(x);
            }
            else if( colorArr[x] == colorArr[top] && G[top][x])
        }

    }

}

int main(){

    int graph[][V] = {{0,1,0,1},
                       {1,0,1,0},
                       {0,1,0,1},
                       {1,0,1,0}};
    
    return 0;
}