class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n= arr.size();
        vector<int>dp(n);
        dp[0]=0;
        for(int i=1; i<n; i++){
        int fs= dp[i-1]+abs(arr[i]-arr[i-1]);
        int ss= 1e9;
        if(i>1)ss= dp[i-2]+abs(arr[i]-arr[i-2]);
        dp[i]= min(fs, ss);
        }
        return dp[n-1];
    }
};