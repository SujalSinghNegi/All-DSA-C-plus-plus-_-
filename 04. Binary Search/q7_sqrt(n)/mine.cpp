class Solution {
  public:
    int floorSqrt(int n) {
      int low =1, high = n;
      while(low <= high){
          int mid = low + (high - low) / 2;
          if(mid * mid == n) return mid;
          if(mid * mid > n) high = mid -1;
          else low = mid+1;
      }
      if(low * low <= n) return low;
      return low - 1;
    }
};