
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
           unordered_map<int,int>mpp;
          int n= arr.size();
          int sum=0, len=0;
          int cnt=0;
          mpp[0]=1;
          for(int i=0; i<n; i++){
              sum+=arr[i];
              if(mpp.find(sum-k)!=mpp.end()){
                  cnt+=mpp[sum-k];
              }
                  mpp[sum]++;
          }
          return cnt;
    }
};