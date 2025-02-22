class Solution {
public:
void backtrack(vector<int>& nums, int n, vector<int>& ds, int ind, vector<vector<int>>&ans){
        ans.push_back(ds);
    for(int i=ind; i<n; i++){
        if(i>ind && nums[i-1]==nums[i])continue;
        ds.push_back(nums[i]);
        backtrack(nums, n, ds, i+1, ans);
        ds.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
         vector<vector<int>>ans;
         vector<int>ds;
         int n= nums.size();
        backtrack(nums, n,ds, 0,ans );
        return ans;
    }
};