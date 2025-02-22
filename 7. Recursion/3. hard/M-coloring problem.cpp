// M-coloring problem
class Solution {
  public:
  // make a function to check the node is safe or not , by checking that color is marked by any adjacent node,
  // if marked then return false otherwise at last return true
 bool isSafe(int node, int c, vector<vector<int>>&adj, vector<int>&color ){
      for(auto it: adj[node]){
          if(color[it]==c) return false;
      }
      return true;
  }
  // a dfs function which will check each node from 0 to v-1, is it safe node to color , and the color is from 0 to m-1 
  // i.e we will try each combination of color starting from 0, then go to the another node, and then we see we cant color it with 0, then we color it 1
  // then on the third node we see we can color it with 0, if it is not connected the first node, 
  // then we will move to the fourth node, then check is it safe likewise we did previosly
  // and if it was safe, but in future that combination didn't work then when backrack we un_mark the the color to -1
  // so thats how we check each node
  
  bool dfs(int node, int m,  vector<vector<int>>&adj, vector<int>&color, int v){
      if(node==v) return 1;
      
      for(int c=0; c<m; c++){
          if(isSafe(node, c, adj, color)){
              color[node]=c;
             if(dfs(node+1,m, adj, color, v ))return 1;
             
          color[node]=-1;
          }
      }
      return 0;
  }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<int>color(v,-1);
        vector<vector<int>>adj(v);
        for(auto it:edges){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        // we dont need to make a for loop for checking the each vertex , wheather it is unmarked or not
        // because in the dfs we explictly going to the each node++, like this, so no matter they are connected or not
        // the algorithm will check the each node, and check weather it is safe node to color with that color or not
        
        return dfs(0, m, adj, color,v);
    }
};