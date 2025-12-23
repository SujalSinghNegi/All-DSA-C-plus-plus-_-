class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>divis(n);
        iota(divis.begin(), divis.end(), 0);
        vector<int>dp(n, 1);
        pair<int,int>ans = {-1, 0};
        for(int i =0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0) {
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        divis[i] = j;
                    }
                }
            }
            if(dp[i] > ans.second) ans = {i, dp[i]};
        }
        vector<int>res;
        res.push_back(nums[ans.first]);
       while(divis[ans.first] != ans.first){
            ans.first=divis[ans.first];
            res.push_back(nums[ans.first]);
       }
        return res;
    }
};