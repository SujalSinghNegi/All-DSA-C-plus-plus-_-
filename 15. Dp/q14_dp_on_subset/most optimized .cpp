class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool>dp(sum+1, 0), cur(sum+1, 0);
        dp[0]=cur[0]=1;
        for( int i = 1; i<= n; i++){
         for(int j= 1; j<= sum; j++){
            bool notTake = dp[j];
            bool take =0;
            if(arr[i-1] <= j ){
                take = dp[j - arr[i-1]];
            }
            cur[j] = notTake | take;
         }   
         dp =cur;
        }
        return dp[sum];
        
    }
};