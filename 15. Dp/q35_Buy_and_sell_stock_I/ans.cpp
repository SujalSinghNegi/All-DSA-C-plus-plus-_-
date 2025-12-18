class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int ans= 0, mini= 1e9;
        for(int i= 0; i<n; i++){
            mini = min(mini, prices[i]);
            ans = max( prices[i] - mini, ans);
        }
        return ans;
    }
};