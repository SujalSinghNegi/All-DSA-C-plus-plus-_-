class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n= arr.size();
       reverse(arr.begin(), arr.end());
       reverse(arr.begin(), arr.begin()+k%n);
       reverse(arr.begin()+k%n, arr.end());

    }
};