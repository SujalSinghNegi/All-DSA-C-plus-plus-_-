class Solution {
public:
int rec(int l, int r, vector<int>&cuts){
    if(l > r) return 0;
    int res= INT_MAX;
    for(int i=l; i<=r; i++){
    int ans = cuts[r+1] - cuts[l-1] + rec(l, i-1, cuts) + rec(i+1, r, cuts);
    res= min(res, ans);
    }
    return res;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        return rec(1, c, cuts);
    }
};