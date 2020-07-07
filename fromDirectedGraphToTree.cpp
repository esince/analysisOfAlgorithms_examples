#include <bits/stdc++.h>

using namespace std;

int find(int x, int a[], int visited[], int root[]){
    if(visited[x] == 1)
        return root[x];
    
    visited[x] = 1;
    root[x] = x;
    root[x] = find(a[x], a, visited, root);
    return root[x];
}
void GraphToTree(int a[], int n){
    int visited[n] = {}, root[n] = {};
    
    for(int i = 0; i < n; i++){
        find(a[i], a, visited, root); //to find parent of each parent
    }

    int rootNode = -1;
    for(int i = 0; i < n ; i++){
        if(i == a[i]){ //if it is ture, then i represents the root of the tree
            rootNode = i;
        }
    }

    if(rootNode == -1){
        for(int i = 0; i < n; i++){
            if(i == find(a[i], a, visited, root)){
                rootNode = i;
                a[i] = i;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) { 
        if (i == find(a[i], a, visited, root)) { 
            a[i] = rootNode; 
        } 
    } 
  
    // Print the resulting array 
    for (int i = 0; i < n; i++) 
        cout << a[i] << " "; 

}
int main(){

    // int a[] = {6, 6, 0, 1, 4, 3, 3, 4, 0 };
    // int a[] = {0,1,2,3,4,5,6};
    int a[] = {1,2,0};
    int n = sizeof(a) / sizeof(a[0]);

    GraphToTree(a, n);
    return 0;
}