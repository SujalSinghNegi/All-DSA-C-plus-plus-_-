class Solution {
  public:
  bool check(vector<int> &arr, int mid, int k){
      int n = arr.size();
      int pre = arr[0];
      int cnt =0;
     for(int i= 1; i<n; i++){
         if(arr[i] - pre >= mid){
             pre =arr[i];
             cnt++;
         }
     }
     return cnt >= k;
  }
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        if(k == 2) return arr[n-1] - arr[0];
        int low = 1, high = (arr[n-1] - arr[0]) / (k -1);
        int ans =0;
        while(low <=high){
            int mid = low + (high - low) /2;
            if(check(arr, mid, k-1)){
                ans = max(ans, mid);
                low = mid+1;
            }else high = mid-1;
        }
        return ans;
    }
};