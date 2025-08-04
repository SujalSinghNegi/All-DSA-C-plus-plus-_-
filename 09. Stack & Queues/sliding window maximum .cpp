class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deque, monotonic, 
        deque<int>dq;
        int n = nums.size();
        vector<int>ans;
        for(int i=0; i<n; i++){ 
            while(!dq.empty() && nums[dq.back()] < nums[i])dq.pop_back();
            if(!dq.empty() && i- dq.front()  >= k )dq.pop_front();
            dq.push_back(i);
            if(i-k+1>=0){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};