class Solution {
public:
    int maxCoins(vector<int>& arr) {
        int n= arr.size();
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        vector<vector<int>>dp(n+2, vector<int>(n+2));
        for(int i= n+1; i>=0; i--){
            for(int j = i+1; j<=n+1; j++){
                if(i+1 >= j) {
                    dp[i][j] =0; continue;
                }
                int ans= 0;
                for(int k = i+1; k<j; k++){
                    ans = max(ans, arr[i] * arr[j] * arr[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n+1] ;
    }
};