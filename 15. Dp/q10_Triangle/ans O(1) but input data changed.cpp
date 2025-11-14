class Solution {
public:
    int minimumTotal(vector<vector<int>>& tr) {
        int n = tr.size();
        for(int i = n-2; i>=0; i--){
            int m = tr[i].size();
            for(int j = 0; j<m; j++){
        tr[i][j] += min(tr[i+1][j],tr[i+1][j+1]);
            }
        }
        return tr[0][0];
    }
};