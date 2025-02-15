class Solution {
public:
void backtrack(vector<vector<int>>&ans, int n,vector<int>&ds, int ind, unordered_map<int,int>all, vector<int>&nums ){
    if(ind ==n){
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<n; i++){
        if(all[nums[i]])continue;
        all[nums[i]]=1;
        ds.push_back(nums[i]);
        backtrack(ans, n, ds, ind+1, all, nums);
        all[nums[i]]=0;
        ds.pop_back();
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n= nums.size();
       unordered_map<int,int>all;
        vector<int>ds;
        backtrack(ans, n, ds, 0, all, nums);
        return ans;
    }
};