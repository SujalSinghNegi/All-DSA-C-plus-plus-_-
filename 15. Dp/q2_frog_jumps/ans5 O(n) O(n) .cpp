class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1e9);
        if(n==1) return 0;
       dp[n-1]=0;
        for(int i=n-1; i>=2; i--){
            dp[i-1]= min(dp[i-1],abs(arr[i]-arr[i-1])+dp[i] );
            dp[i-2]= dp[i]+abs(arr[i-2]-arr[i]);
        }
        int i=1;
        dp[i-1]= min(dp[i-1],abs(arr[i]-arr[i-1])+dp[i] );
     return dp[0];
    }
};
