class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return 0;
        sum/=2;
        vector<bool>dp(sum+1, 0), cur(sum+1, 0);
       dp[0]=cur[0]=1;
        for(int i= 1; i<=n; i++){
            int ele = nums[i-1];
            for(int j= 1; j<=sum; j++){
                bool notTake = dp[j];
                bool take = 0;
                if(j - ele >=0) take = dp[j-ele];
                cur[j] = take | notTake;
            }
            dp=cur;
        }
        return dp[sum];
    }
};