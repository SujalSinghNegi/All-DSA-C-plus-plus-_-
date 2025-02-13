// list method to store the wighted graph
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1]; // or say vector<vector<int>>a(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});// for directed graph this will not include


    }
    return 0;

}
