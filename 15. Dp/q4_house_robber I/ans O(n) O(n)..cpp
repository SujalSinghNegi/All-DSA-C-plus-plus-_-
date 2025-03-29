class Solution {
    public:
        int rob(vector<int>& arr) {
            int n = arr.size();
          vector<int>dp(n+2, 0);
          dp[n+1]=0,dp[n]=0;
          for(int i=n-1; i>=0; i--){
            dp[i]=max(dp[i+2]+arr[i],dp[i+1] );
          }  
          return dp[0];
        }
    };