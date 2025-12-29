// Leetcode 2719. Count of Integers



const int mod= 1e9 + 7;

class Solution {
public:
int dp[24][2][400];
    int mi, ma;
    int rec(int ind, bool tight, int sum, string &s){
        if(sum > ma) return 0;
        if(ind == s.size()) return (sum >= mi && sum<= ma );
        if(dp[ind][tight][sum] != -1) return dp[ind][tight][sum];
        int limit = tight?s[ind] - '0' : 9;
        int ans = 0;
        for(int d= 0; d<= limit; d++){
            int newTight = tight & (d == limit);
            ans = (ans + rec(ind+1, newTight, sum+d, s))%mod;
        }
       return dp[ind][tight][sum] = ans ;
    }
    int count(string n1, string n2, int min_sum, int max_sum) {
        mi = min_sum, ma = max_sum;
        int n = n1.size();
        int i = n - 1;
        while(n1[i] == '0') i--;
        n1[i]--;
        i++;
        while(i<n) {n1[i++]= '9';}
        memset(dp, -1, sizeof(dp));
        int res1 = rec(0, 1, 0, n1);
        memset(dp, -1, sizeof(dp));
        int res2 = rec(0, 1, 0, n2);
        return (res2 - res1 + mod) % mod;

    }
};