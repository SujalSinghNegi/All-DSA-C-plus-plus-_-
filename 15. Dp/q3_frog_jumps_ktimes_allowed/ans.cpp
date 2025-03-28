class Solution {
    public:
        int minimizeCost(int k, vector<int>& arr) {
                int n= arr.size();
            vector<int>dp(n+1, 1e9);
            dp[0]=0;
            for(int i=0; i<n; i++){
                for(int ind = 1; ind<=k && ind+i<n; ind++){
                    dp[ind+i]= min(dp[ind+i], abs(arr[ind+i]-arr[i])+dp[i]);
                }
            }
            return dp[n-1];
    }
    };