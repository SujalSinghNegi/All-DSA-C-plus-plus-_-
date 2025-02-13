// matrix method to store the graph
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int a[n+1][n+1]={0}; 
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        a[u][v]=1;
        a[v][u]=1; // for undirected, 

    }
    return 0;

}
