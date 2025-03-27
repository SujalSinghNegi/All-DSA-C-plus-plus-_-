class Solution {
    public:
      int minCost(vector<int>& arr) {
          // Code here
          int n = arr.size();
          int prev1 =0, prev2=0;
          for(int i=1; i<n; i++){
              int fs =  prev1 + abs(arr[i]-arr[i-1]);
              int ss=1e9;
              if(i>1)ss=prev2+ abs(arr[i]-arr[i-2]);
              int curi= min(fs, ss);
              prev2= prev1;
              prev1 = curi;
          }
          return prev1;
      }
  };