// just like a fibnacci series
class Solution {
public:
    int climbStairs(int n) {
        n=n+1;
        if(n<=1) return n;
        int pre=0, pre2=1;
        for(int i=2; i<=n; i++){
            int cur = pre+pre2;
            pre= pre2;
            pre2=cur;
        }
        return pre2;
    }
};