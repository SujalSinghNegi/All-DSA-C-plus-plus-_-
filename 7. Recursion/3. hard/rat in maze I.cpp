
class Solution {
  public:
  void dfs(int row,int col, string ds, vector<string>&ans,
  vector<vector<int>>&vis, vector<vector<int>>&mat,int n){
      if(row==n-1 && col==n-1){
          ans.push_back(ds);
          return;
      }
      vis[row][col]=1;
      int dx[]=   {0,0,1,-1,};
      int dy[]=   {1,-1,0,0};
      char dir[]= {'R','L', 'D', 'U'};
      for(int k=0; k<4; k++){
          int nrow= dx[k]+row;
          int ncol= dy[k]+col;
          if(nrow>=0 && ncol>=0 && nrow<n &&  ncol < n &&
          mat[nrow][ncol]==1 && !vis[nrow][ncol] ){
              ds+=dir[k];
              dfs(nrow, ncol, ds, ans, vis, mat, n);
              ds.pop_back();
          }
      }
      vis[row][col]=0;
  }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<string>ans;
        string ds;
        int n= mat.size();
        vector<vector<int>>vis(n, vector<int>(n,0));
        dfs(0, 0, ds, ans, vis, mat, n);
        return ans;
        
    }
};