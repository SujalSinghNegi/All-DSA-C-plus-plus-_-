#include<bits/stdc++.h>
#include "my_stdio.h"
using namespace std;

class DisjointSet{
    public:
    vector<int>rank, parent,size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUPair(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPair(parent[node]);
    }
    void unionByRank(int u, int v){
        u = findUPair(u);
        v = findUPair(v);
        if(u==v)return;
        else if(rank[u] < rank[v]){
            parent[u] = v;
        }else if(rank[u] > rank[v]){
            parent[v] = u;
        }else{
            parent[u] = v;
            rank[v]++;
        }
    }
    void unionBySize(int u, int v){
        u = findUPair(u);
        v = findUPair(v);
        if(u==v)return;
        else if(size[u] < size[v]){
            parent[u] = v;
            size[v] += size[u];
        }else{
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
int main(){
   DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // check 3 and 7 same or not
    if(ds.findUPair(3) == ds.findUPair(7)){
        cout<<"Yes same "<<endl;
    }else{
        cout<<"Not same "<<endl;
    }

    ds.unionByRank(3, 7);
   if(ds.findUPair(3) == ds.findUPair(7)){
        cout<<"Yes same "<<endl;
    }else{
        cout<<"Not same "<<endl;
    }

    DisjointSet ds2(7);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(2, 3);
    ds2.unionBySize(4, 5);
    ds2.unionBySize(6, 7);
    ds2.unionBySize(5, 6);
    // check 3 and 7 same or not
    if(ds2.findUPair(3) == ds2.findUPair(7)){
        cout<<"Yes same "<<endl;
    }else{
        cout<<"Not same "<<endl;
    }
    ds2.unionBySize(3, 7);
    if(ds2.findUPair(3) == ds2.findUPair(7)){
          cout<<"Yes same "<<endl;
        }else{
            cout<<"Not same "<<endl;
        }
    


}