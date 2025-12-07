// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n= price.size();
        vector<int>dp(n+1, 0);
        for(int i = 1; i<=n; i++){
            int ele = price[i-1];
            for(int j= i; j<=n; j++){
                dp[j]= max(dp[j], ele + dp[j-i]);
            }
        }
        return dp[n];
    }
};