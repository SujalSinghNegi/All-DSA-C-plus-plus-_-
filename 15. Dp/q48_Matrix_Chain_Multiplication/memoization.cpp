class Solution {
  public:
    int rec(int low , int high, vector<int>&arr,  vector<vector<int>>&dp){
        if(low +1 >= high) return 0;
        if(dp[low][high] != -1) return dp[low][high];
        int ans = 1e9;
        for(int i = low+1; i<high; i++){
        ans = min(ans, arr[low] * arr[i]*arr[high]+ 
    rec(low, i, arr, dp) + rec(i, high, arr, dp));
        }
        return dp[low][high] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n= arr.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return rec(0, n-1, arr, dp);
    }
};