class Solution {
    public:
        int bs(vector<int> &nums, int target, int low, int high){
            if(low>high) return -1;
            int mid = low+ (high-low) /2; // similar to (low+ high) /2
            // we did this because if the high is INT_MAX then the value dont over flow
            if(nums[mid]== target) return mid;
            if(nums[mid]<target) return bs(nums, target, mid+1, high);
            return bs(nums, target, low, mid-1);
        }
        int search(vector<int>& nums, int target) {
           return bs(nums, target, 0, nums.size()-1);
        }
    };