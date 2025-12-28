class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n= arr.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int i= n-1; i>=0; i--){
            for(int j= i+1; j<= n-1; j++){
                if(i+1>=j){dp[i][j] = 0; continue;}
                 int ans = 1e9;
                for(int k = i+1; k<j; k++){
                 ans = min(ans, arr[i] * arr[k]*arr[j]+ dp[i][k] + dp[k][j]);
        }
        dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
};