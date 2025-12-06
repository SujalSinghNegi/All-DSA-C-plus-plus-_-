class Solution {
  public:
  int rec(int i , int target, vector<int>&arr,vector<vector<int>>& dp ){
      if( target == 0) return true;
      if(i == 0 ) return arr[0] == target;
      if(dp[i][target]!= -1) return dp[i][target];
      bool notTake = rec(i-1, target, arr, dp) ;
      bool take = 0;
      if(arr[i] <= target) take = rec(i-1 , target-arr[i], arr, dp);
      return dp[i][target] = take | notTake;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return rec((int)arr.size()-1, sum, arr, dp);
        
    }
};