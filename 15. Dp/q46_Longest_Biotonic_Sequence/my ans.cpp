class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int>left(n, 1);
        for(int i = 0; i<n; i++){
            for(int j= 0; j<i; j++){
                if(nums[i] > nums[j]) 
                left[i] = max(left[i], 1 + left[j]);
            }
        }
        reverse(nums.begin(), nums.end());
        vector<int>right(n, 1);
        int len = 0;
        for(int i = 0; i<n; i++){
            for(int j= 0; j<i; j++){
              if(nums[i] > nums[j] && right[i] < 1 + right[j]){
                    right[i] = 1 + right[j];
                 
                }
            }
            if(right[i] != 1 && left[n -1 - i ] != 1){
            if(len < left[n - i - 1] + right[i] - 1) len = left[n -1- i] + right[i] - 1;
            }
        }
        return len;
    }
};
