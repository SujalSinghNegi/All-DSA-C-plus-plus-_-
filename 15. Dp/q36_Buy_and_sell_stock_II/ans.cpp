class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int mini= 1e9, ans= 0;
        for(int i =0; i<n; i++){
            mini= min(mini, prices[i]);
            if(prices[i] > mini) ans += prices[i] - mini , mini = prices[i];
        }
        return ans;
    }
};