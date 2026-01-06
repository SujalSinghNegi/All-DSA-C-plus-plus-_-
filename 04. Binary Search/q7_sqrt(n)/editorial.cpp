class Solution {
  public:
    int floorSqrt(int n) {
      int low =1, high = n;
      int ans = 1;
      while(low <= high){
          int mid = low + (high - low) / 2;
          if(mid * mid == n) return mid;
          if(mid * mid > n) high = mid -1;
          else ans = mid, low = mid+1 ;
      }
   return ans;
    }
};