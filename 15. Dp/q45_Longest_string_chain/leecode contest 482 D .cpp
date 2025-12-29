//3791. Number of Balanced Integers in a Range

#define ll long long
class Solution {
public:
    ll dp[20][2][400];
    ll rec(int ind, bool tight, int sum, string &s){
        if(ind == s.size()) return (sum == 200); 
        if(dp[ind][tight][sum] != -1) return dp[ind][tight][sum];
        int limit = tight?s[ind] - '0' : 9;
        ll ans = 0;
        for(int d = 0; d<=limit; d++){
            int newTight = tight & (d == limit);
            ans += rec(ind+1, newTight, sum + ((ind&1)? d: -d) , s);
        }
        return dp[ind][tight][sum] = ans;
    }
    long long countBalanced(long long low, long long high) {
        string n1 = to_string(low-1);
        string n2 = to_string(high);
        memset(dp, -1, sizeof(dp));
        ll res1 = rec(0, 1, 200, n1);
        memset(dp, -1, sizeof(dp));
        ll res2 = rec(0, 1, 200, n2);

        return res2  - res1;
    }
};