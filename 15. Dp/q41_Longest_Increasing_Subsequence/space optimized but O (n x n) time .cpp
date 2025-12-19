class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>cur(n+2, 0), ahead(n+2, 0);
        for(int i= n; i>=1; i--){
            for(int j = n; j>=0; j--){
                cur[j] = ahead[j];
                if( j == 0 || nums[i-1] > nums[j-1]){
                    cur[j] = max(cur[j], 1 + ahead[i]);
                }
            }
            ahead = cur;
        }
        return cur[0];
    }
};