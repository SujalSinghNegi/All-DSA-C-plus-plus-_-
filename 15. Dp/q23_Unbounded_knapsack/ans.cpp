
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
               vector<int>dp(capacity+1, 0);
              // dp[0]=0;
               int n= wt.size();
               for(int i= 0; i<n; i++){
                int ele = wt[i];
                for(int sum = ele ; sum <= capacity ; sum++){
                        dp[sum] = max(dp[sum], dp[sum - ele] + val[i]);
                }
               }    
               return dp[capacity];
    }
};