class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        int t = 2*n -1;
        vector<int>res(n);
        while(t>=0){
            while(!st.empty() && st.top() <= nums[t%n])st.pop();
            if(t < n){
                if(!st.empty() && st.top() > nums[t]) res[t]= st.top();
                else res[t] =-1;
            }
            st.push(nums[t%n]);
            t--;
        }
        return res;
    }
};