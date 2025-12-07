#define ll long long
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<ll>dp(amount + 1, 4e18);
        if(amount ==  0) return 0;
        int n= coins.size();
        sort(coins.begin(), coins.end(), greater<int>());
        dp[0]=1;
        for(int i = 0; i<n; i++){
            ll ele = coins[i];
            for(ll sum = ele; sum <= amount; sum++){
                if(dp[sum - ele] != 4e18)
                dp[sum] = min(dp[sum], dp[sum - ele]  + 1);
            }
        }
      if(dp[amount] == 4e18) return -1;
      return dp[amount]-1;
    }
};