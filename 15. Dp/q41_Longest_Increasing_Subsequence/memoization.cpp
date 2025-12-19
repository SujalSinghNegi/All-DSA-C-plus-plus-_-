class Solution {
public:
    int rec(int i, vector<int> &nums, int j, int n, vector<vector<int>>&dp){
        if(i > n) return 0;
        if(dp[i][j] != -1) return dp[i][j]; 
        int ans = rec(i+1, nums, j, n, dp);
        if( j == 0 || nums[i-1] > nums[j-1]){
            ans = max(ans, 1 + rec(i+1, nums, i, n, dp));
        }
        return dp[i][j] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return rec(1, nums, 0, n, dp);
    }
};