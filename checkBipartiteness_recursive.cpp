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
bool  colorGraph(int G[][V], int colorArr[], int pos, int c ){

    if(colorArr[pos] != -1 && colorArr[pos] != c)
        return false;
    //color this position as c and all its neighbors as 1-c
    colorArr[pos] = c;

    bool ans = true;
    
    for(int x  = 0; x < V; ++x){
        if(G[pos][x]){
            if(colorArr[x] == -1){
                ans &= colorGraph(G, colorArr, x, 1-c);
            }
            if( colorArr[x] != -1 && colorArr[x] != 1-c){
                return false;
            }

        }
        if(!ans)
            return false;
    }

    return true;
}
//returns true if G[V][V] is bipartite
bool isBipartite(int G[][V]){
    int colorArr[V]; 
    
    //-1: no color, 0: blue, 1: red
    //initialization of colorArr[]
    for(int i = 0; i< V; i++){
        colorArr[i] = -1;
    }

    int pos = 0;

    return colorGraph(G, colorArr, pos, 1);
}

//driver code
int main(){
 
    int graph[][V] = {{0,1,0,0},
                       {0,0,1,0},
                       {0,1,0,1},
                       {1,0,1,0}};
    isBipartite(graph) ? cout << "Yes" : cout << "No"; 
    
    return 0;
}