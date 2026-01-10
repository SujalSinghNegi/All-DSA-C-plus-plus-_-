class Solution {
  public:
  bool check(int mid, vector<int> &arr, int k){
      int cnt =1, sum= 0;
      for(int num: arr){
          if(sum + num <= mid){
              sum+= num;
          }else{
              sum =num;
              cnt++;
          }
      }
      return cnt <= k;
  }
    int minTime(vector<int>& arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end());
        int high =accumulate(arr.begin(), arr.end(), 0);
        int ans = high;
        while(low <= high){
            int mid = low + (high- low)/2;
            if(check(mid, arr, k)){
                ans = min(ans, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};