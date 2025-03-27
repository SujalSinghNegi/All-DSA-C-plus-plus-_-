class Solution {
  public:
  int rec(int ind,  vector<int>&arr,int n){
      if(ind==0) return 0;
      int left = abs(arr[ind]-arr[ind-1])+ rec(ind-1,arr,n);
    int right =ind>1 ? (abs(arr[ind]-arr[ind-2])+rec(ind-2, arr, n)):1e9;
    return min(left, right);
      
  }
    int minCost(vector<int>& arr) {
        int n= arr.size();
        return rec(n-1, arr, n);
    }
};