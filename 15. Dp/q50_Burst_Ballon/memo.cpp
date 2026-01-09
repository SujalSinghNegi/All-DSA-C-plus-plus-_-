class Solution {
public:
  int rec(int low , int high, vector<int>&arr, vector<vector<int>>&dp){
        if(low +1 >= high) return 0;
        int ans = 0;
        if(dp[low][high] != -1) return dp[low][high];
        for(int i = low+1; i<high; i++){
        ans = max(ans, arr[low] * arr[i]*arr[high]+ 
    rec(low, i, arr, dp) + rec(i, high, arr, dp));
        }
        return dp[low][high]= ans;
    }
    int maxCoins(vector<int>& arr) {
        int n= arr.size();
        if(n == 1) return arr[0];
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        vector<vector<int>>dp(n+2, vector<int>(n+2, -1));
        return rec(0, n+1, arr, dp) ;
    }
};