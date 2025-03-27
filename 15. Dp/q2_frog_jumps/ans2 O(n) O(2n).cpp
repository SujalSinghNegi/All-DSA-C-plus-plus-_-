
class Solution {
    public:
    int rec(int ind, vector<int>&dp, vector<int>& arr){
        if(ind==0) return 0;
        int left = abs(arr[ind]-arr[ind-1])+((dp[ind-1]!=-1) ? dp[ind-1]:( dp[ind-1]=rec(ind-1, dp, arr)));
      int right =ind>1 ? (abs(arr[ind]-arr[ind-2])+((dp[ind-2]!=-1) ? dp[ind-2]:( dp[ind-2]=rec(ind-2, dp, arr)))):1e9;
      return min(left, right);
        
    }
      int minCost(vector<int>& arr) {
          int n= arr.size();
          vector<int>dp(n, -1);
          dp[n-1]=0;
          return rec(n-1, dp, arr);
      }
  };
  