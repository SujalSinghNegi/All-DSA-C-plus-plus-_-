class Solution {
  public:
  int rec(int j, vector<vector<int>> &cost,
  int n, int vis,vector<vector<int>> &dp ){
      if(vis == (1<<n) - 1) return cost[j][0];
      if(dp[j][vis] != -1) return dp[j][vis];
      int ans = 1e9;
      for(int k= 1; k<n; k++){
          if(k == j) continue;
          if(!(vis&(1<<k))){
   ans= min(ans, cost[j][k] + rec(k, cost, n, vis|(1<<k), dp));
          }
      }
      return dp[j][vis] = ans;
  }
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
       vector<vector<int>>dp(n, vector<int>(1<<n, -1));
        return rec(0, cost, n, 1, dp);
    }
};