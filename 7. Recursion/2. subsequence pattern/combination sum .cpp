class Solution {
public:

    void allKsum(vector<int>& candidates, int n, int target,vector<int>&ds, int ind, vector<vector<int>>&ans){
        if(ind==n){
            if(0==target){
                ans.push_back(ds);
            }
             return;
        }
        if(candidates[ind]<= target){
           ds.push_back(candidates[ind]);
           allKsum(candidates, n, target-candidates[ind], ds, ind, ans);
              ds.pop_back();
        }
     
        allKsum(candidates, n, target, ds, ind+1, ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        int n= candidates.size();
        allKsum(candidates, n, target, ds, 0, ans);
        return ans;

    }
};