class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // what i could think -> 
        /*
        for for the max element, find and start from there, 

        */
        int n= nums.size();
        int maxa = INT_MIN;
        int ind=0;
        for(int i=0; i<n; i++){
            if(maxa < nums[i]){
                maxa = nums[i];
                ind =i;
            }
        }
        
        stack<int>st;
        vector<int>ans(n);
        int s = n;
        
        while(s--){ 
            while(!st.empty() && st.top() <= nums[ind])st.pop();
            if(st.empty()) ans[ind]= -1;
            else ans[ind]= st.top();
            st.push(nums[ind]);
            ind--;
            if(ind ==-1) ind = n-1;
        }
        return ans;
    }
};