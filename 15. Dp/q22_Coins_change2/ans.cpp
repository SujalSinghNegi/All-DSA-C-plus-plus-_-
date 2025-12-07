class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount + 1,0);
        dp[0]=1;
        int n = coins.size();
        for(int i= 0; i<n; i++){
            int ele = coins[i];
            for(int sum = ele; sum <= amount ; sum++){
            long long temp = (long long)dp[sum] + (long long )dp[sum - ele] ;
                if(temp > INT_MAX) break; // because question says all answers are in 32 bit integers, so if the dp is overflowing integrer it means it is not contributing to the solution, 
                dp[sum] = temp;
            }
        }
        return dp[amount];
    }
};