#define ll long long
class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        ll low = *min_element(b.begin(), b.end()), high = *max_element(b.begin(), b.end());
        ll res= 2e9;
        int n = b.size();
        while( low <= high){
            ll mid = low + (high - low ) /2;
            ll ans = 0;
            ll cnt =0;
            for(ll i= 0; i<n; i++){
                if(b[i] <= mid) cnt++;
                else cnt = 0;
                if(cnt >= k){
                    ans++;
                    cnt=0;
                }
            }
            if( ans >= m){
                res = min(res, mid);
                high = mid-1;
            }else low = mid+1;
        }
        if(res == 2e9) return -1;
        return (int)res;
    }
};