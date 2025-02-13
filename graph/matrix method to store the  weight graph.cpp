// matrix method to store the  wight graph
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int a[n+1][n+1]={0}; 
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w; // for undirected, 

    }
    return 0;

}
