#define ll long long
class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        ll low = *max_element(w.begin(), w.end());
        ll high = accumulate(w.begin(), w.end(), 0LL);
        int n = w.size();
        ll ans = high;
        while(low <= high){
            ll mid = low + (high - low) / 2;
            ll sum =0;
            ll d= 0;
            for(int i=0; i<n; i++){
                if(sum + w[i] <= mid){
                    sum+=w[i];
                }else{
                    sum = w[i];
                    d++;
                }
            }
             d++;
            if(d > days){
                low = mid+1;
    
            }else{
                ans =min(ans, mid);
                high = mid-1;
            }
        }
        return ans;
    }
};