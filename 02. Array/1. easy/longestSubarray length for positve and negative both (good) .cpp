
class Solution {
    public:
      int longestSubarray(vector<int>& arr, int k) {
          // code here
          unordered_map<int,int>mpp;
          int n= arr.size();
          int sum=0, len=0;
          for(int i=0; i<n; i++){
              sum+=arr[i];
              if(mpp.find(sum-k)!=mpp.end()){
                  len= max(len, i-mpp[sum-k]);
              }
              if(sum==k){
                  len = i+1;
              }
              if(mpp.find(sum)==mpp.end()){
                  mpp[sum]=i;
              }
          }
          return len;
      }
  };

/*
// my approach also similar
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
  */