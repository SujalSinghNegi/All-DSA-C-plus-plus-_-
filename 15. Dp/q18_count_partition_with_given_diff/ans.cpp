class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
      
        /*
        use the bottom up technique, like
        starting from the sum =  max to the element, and then 
        dp[sum] += dp[sum - ele]
        
        have to partition into two subset with diff = d;
        a - b = d;
        and a + b = total
        so a = (d + total) / 2
        and (d + total) must be even for correct answer and partition
        and d < total, 
        */
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(((total + d) & 1) || total < d) return 0;
        int MAX = (total + d)/2;
        vector<int>dp(MAX +1,0);
        dp[0]=1;
        for(int i = 0; i<n; i++){
            int ele = arr[i];
            for(int sum = MAX; sum>=ele; sum--){
                dp[sum]+= dp[sum - ele];
            }
        }
      
        
        return dp[MAX];
    }
};