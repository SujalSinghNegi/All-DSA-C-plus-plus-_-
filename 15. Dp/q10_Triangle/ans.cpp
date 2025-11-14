class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr) {
            int n = tr.size();
        int p= tr[n-1].size();
        vector<int>dp(p, 1e9);
        dp[0]=tr[0][0];
        for(int i  = 1; i<n; i++){
            int m = tr[i].size();
            for(int j =m-1;j>=0; j--){
                int upleft = 1e9;
                int up = dp[j];
                if(j>0) upleft = dp[j-1];
                dp[j] = min(upleft, up)+tr[i][j];
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};