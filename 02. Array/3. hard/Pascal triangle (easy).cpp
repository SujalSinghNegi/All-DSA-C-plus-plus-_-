class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int j=1; j<n; j++){
            vector<int>level;
            level.push_back(1);
            for(int i=1; i<=j-1; i++){
                level.push_back(ans[j-1][i-1]+ans[j-1][i]);
            }
            level.push_back(1);
            ans.push_back(level);
        }
        return ans;

    }
};