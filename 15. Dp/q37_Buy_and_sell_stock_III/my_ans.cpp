class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m1 = 0, m2 = 0;
        int n= prices.size();
        vector<int>left(n);
        int mini=1e9;
        for(int i = 0; i<n; i++){
            mini= min(mini, prices[i]);
            if(i>0)left[i] = max(left[i-1] , prices[i] - mini);
        }
        int maxa= 0;
        int ans = 0;
        for(int i= n-1; i>=0; i--){
            maxa = max(maxa, prices[i]);
            ans = max(ans, left[i] + maxa - prices[i] );
        }
        return ans;
    }
};