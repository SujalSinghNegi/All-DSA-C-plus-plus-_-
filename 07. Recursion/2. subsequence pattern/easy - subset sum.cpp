class Solution {
  public:
    vector<int> ans;
    void backtrack(vector<int>&arr, int n , int ind, int sum){
        if(ind==n){
            ans.push_back(sum);
            return;
        }
        
        backtrack(arr, n ind+1, sum+arr[ind]);
        backtrack(arr, n, ind+1, sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n= arr.size();
        backtrack(arr, n, 0, 0);
        return ans;
        
    }
};
