class Solution {
public:
  int rec(int low , int high, vector<int>&arr){
        if(low +1 >= high) return 0;
        int ans = 0;
        for(int i = low+1; i<high; i++){
        ans = max(ans, arr[low] * arr[i]*arr[high]+ 
    rec(low, i, arr) + rec(i, high, arr));
        }
        return ans;
    }
    int maxCoins(vector<int>& arr) {
        int n= arr.size();
        if(n == 1) return arr[0];
        arr.insert(arr.begin(), 1);
        arr.push_back(1);
        return rec(0, n+1, arr) ;
    }
};