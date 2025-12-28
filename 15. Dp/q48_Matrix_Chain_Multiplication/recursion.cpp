class Solution {
  public:
    int rec(int low , int high, vector<int>&arr){
        if(low +1 >= high) return 0;
        int ans = 1e9;
        for(int i = low+1; i<high; i++){
        ans = min(ans, arr[low] * arr[i]*arr[high]+ 
    rec(low, i, arr) + rec(i, high, arr));
        }
        return ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n= arr.size();
        return rec(0, n-1, arr);
    }
};