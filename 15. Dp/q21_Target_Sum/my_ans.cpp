
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
    int t= accumulate(nums.begin(), nums.end(), 0);
    if(t < abs(target)) return 0; // total sum added or subtracted is lesser than target
    
        vector<int>dp( 2 * t + 1, 0); // for storing the positive and negative numbers 
        /*
    -t to -1        indexing is = > 0 to t
     0 to t         indexing is = > t to 2t
    total = t + 1 + t => 2 * t +1
        */
    
        dp[t] =1;
        for(int i= 0; i<n; i++){
            int ele= nums[i];
            vector<int>l(2*t + 1, 0), r(2*t + 1, 0);
            for(int sum = 2*t ; sum >= ele ; sum--){
                l[sum] += dp[sum - ele];
            }
            for(int sum = ele; sum <= 2*t; sum++){
                r[sum - ele] += dp[sum];
            }
           if(i == 0) dp[t]=0;
            for(int j =0; j<= 2 * t; j++){
                int c= l[j] + r[j];
                if(c ==0)dp[j]=0;
                else dp[j] = c;
            }
        }
    
        return dp[t + target];
    }
};