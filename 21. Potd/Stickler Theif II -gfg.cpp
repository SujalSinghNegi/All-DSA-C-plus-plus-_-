class Solution {
  public:
  int count(int ind, int n, vector<int>&arr){
      // with DP
        // vector<int>dp(n+2);
        // dp[n+1]=0, dp[n]=0;
        // for(int i=n-1; i>=ind; i--){
        //     dp[i]= max(dp[i+2]+arr[i], dp[i+1]);
        // }
        // return dp[ind];
        // Without DP
        int first = 0, second =0;
        for(int i=n-1; i>=ind; i--){
            int temp = first;
             first= max(second+arr[i], first);
             second = temp;
         }
         return first;
      
  }
    int maxValue(vector<int>& arr) {
        int n= arr.size();
        return max(count(0,n-1, arr), count(1,n, arr));
    }
};