/*
84. Largest Rectangle in Histogram
Solved
Hard
Topics
premium lock iconCompanies

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4

 

Constraints:

    1 <= heights.length <= 105
    0 <= heights[i] <= 104


*/

class Solution {
public:
 vector<int> getnse(vector<int>&nums){
        int n= nums.size();
        stack<int>st;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i])st.pop();
            if(st.empty())ans[i]= n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
     vector<int> getpse(vector<int>&nums){
        int n= nums.size();
        stack<int>st;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
        while(!st.empty() && nums[st.top()] > nums[i])st.pop();
            if(st.empty())ans[i]= -1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>nse = getnse(heights);
        vector<int>pse = getpse(heights);
       int maxa = 0;
       int n = heights.size();
        for(int i=0; i<n; i++){
            maxa = max(maxa, (nse[i]-pse[i]-1)*heights[i]);
        }
        return maxa;

    }
};

