#define ll long long
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        ll low = 1, high = m;
        if(m == 0) return 0;
        while(low <= high){
            ll mid = low + (high- low) / 2;
            ll x= pow(mid, n);
            if(x == m) return mid;
            if( x < m) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};