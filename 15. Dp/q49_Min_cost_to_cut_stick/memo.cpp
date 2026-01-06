class Solution {
public:
vector<vector<int>>dp;
int rec(int l, int r, vector<int>&cuts){
    if(l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int res= INT_MAX;
    for(int i=l; i<=r; i++){
    int ans = cuts[r+1] - cuts[l-1] +
     rec(l, i-1, cuts) + rec(i+1, r, cuts);
    res= min(res, ans);
    }
    return dp[l][r] = res;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        dp.resize(c+3, vector<int>(c+3, -1));
        return rec(1, c, cuts);
    }
};