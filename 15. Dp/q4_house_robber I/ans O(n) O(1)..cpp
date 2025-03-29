class Solution {
    public:
        int rob(vector<int>& nums) {
            int n= nums.size();
            int next1=0, next2=0;
            for(int i= n-1; i>=0; i--){
                int cur = max(next1, next2+nums[i]);
                next2= next1;
                next1= cur;
            }
            return next1;
        }
    };