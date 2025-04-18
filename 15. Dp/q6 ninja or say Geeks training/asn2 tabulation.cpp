class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n= arr.size();
        vector<vector<int>>dp(n+1, vector<int>(3));
        dp[n][0]=dp[n][1]=dp[n][2]=0;
        for(int i=n-1; i>=0; i--){
            dp[i][0]= max(dp[i+1][1], dp[i+1][2])+arr[i][0];
            dp[i][1]= max(dp[i+1][0], dp[i+1][2])+arr[i][1];
            dp[i][2]= max(dp[i+1][1], dp[i+1][0])+arr[i][2];
            
        }
        return max({dp[0][0], dp[0][1], dp[0][2]});
    }
};