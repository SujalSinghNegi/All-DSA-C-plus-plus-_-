class Solution {
    public:
      int longestSubarray(vector<int>& arr, int k) {
          // code here
          unordered_map<int,int>mpp;
          int sum=0;
          int n=arr.size();
          for(int i=0; i<n; i++){
              sum+=arr[i];
              mpp[sum]=i;
          }
          int s=0;
          int maxa= 0;
          for(int i=0; i<n ; i++){
              
              if(mpp[k+s]){ // if(mpp.find(k+s)!= mpp.end())
                  maxa= max(mpp[k+s]-i+1, maxa);
              }
              s+=arr[i];
          }
          return maxa;
      }
  };