class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        auto it= upper_bound(arr.begin(), arr.end(), x);
        return it==arr.begin()?-1: it-arr.begin()-1  ;
    }
};