class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n, 1) ;
        vector<int>lis(n);
        iota(lis.begin(), lis.end(), 0);
        int ans = -1;
        for(int i= 0; i<n; i++){
            for(int j =0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(dp[i] < dp[j] +1){
                    dp[i] =  1+dp[j];
                    lis[i] = j;
                    }
                }
            }
            if(ans == -1 || dp[ans] < dp[i]){
                ans = i;
            }
        }
        vector<int>res;
       while(ans != lis[ans]){
           res.push_back(nums[ans]);
           ans= lis[ans];
       }
       res.push_back(nums[ans]);
       reverse(res.begin(), res.end());
        return res;
    }
};