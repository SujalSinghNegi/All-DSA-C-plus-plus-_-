#define ll long  long
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        ll n= piles.size();
        ll low = 1, high = *max_element(piles.begin(), piles.end());
        ll res= high;
       while(low <= high){
            ll mid = low + (high -  low)/2;
            ll cnt = 0;
            for(int j= 0; j<n; j++){
              cnt +=  ((piles[j] + mid -1)/ mid);
            }
            if(cnt <= h){
                res = min(res, mid);
                high = mid-1;
            }else low = mid + 1;
        }
        return res;
    }
};