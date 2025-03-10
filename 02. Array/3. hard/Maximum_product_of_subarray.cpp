class Solution {
public:
    int maxProduct(vector<int>& arr) {
        // if the zero occurs the procedure restart
        // ideally if the zero is there we have to go to the left to right at that index and then multiply the prefix,  and right to left, and multiply the suffix
        // then the max of these two will the max at that subaaraay till zero.
        // but we can do it in one go by following the prefix from left to right, and suffix from right to left.
        
        int n= arr.size();
        int pre = 1, suff=1, maxa= INT_MIN;
        for(int i=0; i<n; i++){
           if(pre==0)pre=1;
           if(suff==0)suff=1;
            pre*= arr[i];
            suff*= arr[n-1-i];
            maxa= max(maxa, max(pre, suff));

        }
        return maxa;
    }
};