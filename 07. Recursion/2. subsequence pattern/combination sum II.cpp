class Solution {
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    void Ksum(vector<int> &arr, int n , int ind, int target,vector<int> &ds,
    vector<vector<int>> & ans){
            if(target ==0){
                ans.push_back(ds);
                return;
            }
           
         for(int i=ind; i<n; i++){
             if(i> ind && arr[i-1]==arr[i])continue ;
             if(arr[i] > target)break;
            ds.push_back(arr[i]);
            Ksum(arr, n, i+1, target-arr[i], ds, ans);
            ds.pop_back();
         }
        
    }
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        // Your code here
        int n= arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        vector<int>ds;
        Ksum(arr, n, 0, target, ds, ans);
        return ans;
    }
};