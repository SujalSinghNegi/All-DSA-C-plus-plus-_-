class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        // find and then go untill find other elment, 
        int n = nums.size();
        int lb = lower_bound(nums.begin(), nums.end(), x)- nums.begin();
        if(lb==n || nums[lb]!= x) return {-1, -1};
        int ub = upper_bound(nums.begin(), nums.end(), x)-nums.begin();
        return {lb, ub-1};
      
    }
};