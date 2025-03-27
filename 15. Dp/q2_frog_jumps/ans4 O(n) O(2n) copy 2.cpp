class Solution {
  public:
  int rec(int ind, vector<int>&dp, vector<int>& arr){
      if(ind==0) return 0;
      if(dp[ind]!=-1) return dp[ind];
      int left = abs(arr[ind]-arr[ind-1])+rec(ind-1, dp, arr);
    int right =ind>1 ? (abs(arr[ind]-arr[ind-2])+rec(ind-2, dp, arr)):1e9;
    return dp[ind]=min(left, right);
      
  }
    int minCost(vector<int>& arr) {
        int n= arr.size();
        vector<int>dp(n, -1);
        return rec(n-1, dp, arr);
    }
};