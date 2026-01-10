class Solution {
  public:
  int check(int mid, vector<int> &arr, int k, int n){
      int sum = 0;
      int cnt =1;
      for(int i=0; i<n; i++){
          if(sum + arr[i] <= mid){
              sum+= arr[i];
          }else{
              sum = arr[i];
            cnt++;
          }
      }
      return cnt <= k;
  }
    int findPages(vector<int> &arr, int k) {
        int n= arr.size();
        if(n < k) return -1;
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int mini = *max_element(arr.begin(), arr.end());
        int low = mini, high = sum;
        int ans = sum;
        while(low <= high){
            int mid = low + (high - low)/2;
            bool pos = check(mid, arr, k , n);
            if(pos){
                ans = min(ans, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};