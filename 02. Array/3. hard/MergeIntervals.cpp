class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
         int n = arr.size(); 
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        // if the ans is empty, then push it to the ans, or if the current first index is greater than previously pushed last element, 
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
       // now the second index of the previously pushed index is maximize by the ahead upcoming max index at in the interval
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}
};