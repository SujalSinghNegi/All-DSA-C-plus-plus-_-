class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,1), pos(n, 1);
        int ans = -1;
        for(int i = 0; i<n; i++){
            for(int j= 0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i] < dp[j] + 1){
                    dp[i] = max(dp[i], 1+dp[j]);
                        pos[i] = pos[j];
                    }
                  else if(dp[i] == 1+dp[j])pos[i]+=pos[j];
                }
            }
                if(ans == -1 || dp[i]> dp[ans]) ans = i;
        }
        int res = 0;
        for(int i= 0; i<n; i++){
            if(dp[ans] == dp[i])res+=pos[i];
        }
        return res;
    }
};