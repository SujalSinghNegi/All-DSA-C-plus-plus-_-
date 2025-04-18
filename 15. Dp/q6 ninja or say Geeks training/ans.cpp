class Solution {
    public:
      int back(int ind,int last, vector<vector<int>>& arr, vector<vector<int>>& dp){
          if(ind ==0){
              int maxi = 0;
              for(int i=0; i<3; i++){
                  if(i==last)continue;
                  maxi = max(maxi, arr[0][i]);
              }
              return dp[0][last]=maxi;
          }
           int maxi = 0;
           if(dp[ind][last]!=-1)return dp[ind][last];
           for(int i=0; i<3; i++){
                  if(i==last)continue;
                  maxi = max(maxi, arr[ind][i]+ back(ind-1, i, arr, dp)) ;
          }
          return dp[ind][last]=maxi;
      }
      
      int maximumPoints(vector<vector<int>>& arr) {
         
          int n= arr.size();
          vector<vector<int>>dp(n+1, vector<int>(4, -1));
       
          return back(n-1, 3, arr, dp);
      }
  };