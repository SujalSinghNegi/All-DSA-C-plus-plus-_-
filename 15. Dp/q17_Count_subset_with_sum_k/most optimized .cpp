class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
    vector<int>dp(target+1, 0);
    dp[0]=1;
    int n = arr.size();
    for(int i =0; i<n; i++){
        int ele = arr[i];
    for(int sum = target; sum>= ele; sum--){
        dp[sum]+= dp[sum-ele];
    }
    }
    return dp[target];
    }
};

