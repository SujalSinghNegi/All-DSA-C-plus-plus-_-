class Solution {
public:
    int rec(int i, vector<int> &nums, int j, int n){
        if(i == n) return 0;
        int ans = 0;
        if(j == -1 || nums[i] > nums[j]){
            ans = 1 + rec(i+1, nums, i, n);
        }
        return max(ans, rec(i+1, nums, j, n));
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        return rec(0, nums, -1, n);
    }
};