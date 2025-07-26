/*
907. Sum of Subarray Minimums
Solved
Medium
Topics
premium lock iconCompanies

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

 

Constraints:

    1 <= arr.length <= 3 * 104
    1 <= arr[i] <= 3 * 104


*/

class Solution {
public:
const int mod = 1e9 + 7;
vector<int>findnse(vector<int>&arr){
    int n = arr.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]>= arr[i])st.pop();
        if(st.empty())ans[i]= n;
        else ans[i]= st.top();
        st.push(i);
    }
    return ans;
}
vector<int>findpse(vector<int>&arr){
    int n = arr.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] > arr[i])st.pop();
        if(st.empty())ans[i]= -1;
        else ans[i]= st.top();
        st.push(i);
    }
    return ans;

}
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse = findnse(arr);
        vector<int>pse = findpse(arr);
        int sum  =0, n= arr.size();
        // for(int i =0; i<n; i++){
        //     cout<<nse[i]<<" ";
        // }
        // cout<<endl;
        // for(int i =0; i<n; i++){
        //     cout<<pse[i]<<" ";
        // }
        // cout<<endl;
        for(int i = 0; i<n; i++){
            sum = (sum + (1LL*(nse[i]- i ) * (i-pse[i])*arr[i])%mod)%mod;
        }

        return sum;
    }
};