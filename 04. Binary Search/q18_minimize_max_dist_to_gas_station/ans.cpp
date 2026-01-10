class Solution {
  public:
  bool check(double mid, vector<int>&arr, int k){
      int n = arr.size();
      for(int i=1; i<n; i++){
          if(double(arr[i] - arr[i-1]) > mid){
              k-=ceil(double(arr[i] - arr[i-1])/mid - 0.000001) - 1;
          }
      }
    return (k>=0);
  }
    double minMaxDist(vector<int> &arr, int k) {
        double low = 0.000001;
        double high = 1e6;
        // removed the part which also get the minimum high, by calculating the diffrence of each adjacent elment, but no need to do that optimization.
        int n = arr.size();
        double ans = high; 
         while(high - low >= 0.000001){
         double mid = double((high + low)/2.0);
        if(check(mid, arr, k)){
            ans = min(ans, mid);
            high =  mid;
        }else{
            low = mid ;
        }
        }
        return ans;
    }
};