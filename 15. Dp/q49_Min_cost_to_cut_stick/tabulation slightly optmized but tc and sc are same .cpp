class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>>dp(c+3, vector<int>(c+3, 0));
    
        for(int l = c; l>=1; l--){
            for(int r = l; r<=c; r++){
                int res = INT_MAX;
                for(int k = l; k<=r; k++){
                int ans = cuts[r+1] - cuts[l-1] + dp[l][k-1] + dp[k+1][r];
                   res = min(res, ans);
                }
                dp[l][r] = res;
            }
        }
        return dp[1][c];
    }
};