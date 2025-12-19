class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>dp(n+2, vector<int>(n+2, 0));
        for(int i= n; i>=1; i--){
            for(int j = n; j>=0; j--){
                dp[i][j] = dp[i+1][j];
                if( j == 0 || nums[i-1] > nums[j-1]){
                    dp[i][j] = max(dp[i][j], 1 + dp[i+1][i]);
                }
            }
        }
        return dp[1][0];
    }
};