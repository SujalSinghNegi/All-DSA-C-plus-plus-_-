


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            at each index i = 1, 2, 3, 4, .. n
            what we are doing = +, -, + , -, .. +
            like this we can partition all +, +, +, + , all -, -, -, -
            then we can say that any final experssion is nothing but , the parition the array into two subset with diffrence = target 
            so we have to count the total no. of ways of that subset which make this diff = taraget

        */
        int total = accumulate(nums.begin(), nums.end(), 0);
        /*
        we want = a - b = target, and have a+b = total
        so a = (target + total )/ 2
        */
        if( (total + target) % 2 != 0  || abs(target) > total  ) return 0;
        int a = (total + target) / 2 ; 
        vector<int>dp(a + 1, 0); // find subset with sum = a
        dp[0]= 1;
        int n= nums.size();
        for(int i = 0; i<n; i++){
            int ele = nums[i];
            for(int sum = a; sum >= ele ; sum--){
                dp[sum] += dp[sum - ele];
            }
        }
            return dp[a];
    }
};