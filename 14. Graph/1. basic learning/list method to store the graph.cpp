// list method to store the graph
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>adj[n+1]; // or say vector<vector<int>>a(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);// for directed graph this will not include


    }
    return 0;

}
