class Solution {
  public:
  int rec(int i , int target, vector<int>&arr ){
      if( target == 0) return true;
      if(i == 0 ) return arr[0] == target;
      bool notTake = rec(i-1, target, arr) ;
      bool take = 0;
      if(arr[i] <= target) take = rec(i-1 , target-arr[i], arr);
      return take | notTake;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return rec((int)arr.size()-1, sum, arr);
        
    }
};