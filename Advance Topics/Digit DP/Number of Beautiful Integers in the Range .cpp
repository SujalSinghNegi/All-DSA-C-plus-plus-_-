class Solution {
public:
    int offset = 10;
    int dp[10][2][25][22][2];
    int k;
    int rec(int ind, bool tight, int even, int rem, bool start, string &s){
        if(ind == s.size()) return (even == offset) && (rem == 0);
        if(dp[ind][tight][even][rem][start] != -1) return dp[ind][tight][even][rem][start];
        int limit = tight?s[ind] -'0' : 9;
        int ans = 0;
        for(int d =0; d<=limit; d++){
            bool nt = tight & (d == limit);
        ans+= rec(ind+1,
        nt,
        even + ((d&1)? -1 :  1) - int(start & (d == 0)),
        (rem + ((d * (int)pow(10, (int)s.size() - ind - 1))%k))%k ,
        start & (d == 0), 
        s);


        }
        return dp[ind][tight][even][rem][start] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        this->k = k;
        string n1 = to_string(low-1);
        string n2 = to_string(high);
        memset(dp, -1, sizeof(dp));
        int res1 = rec(0, 1, offset, 0,true, n1);
        memset(dp, -1, sizeof(dp));
        int res2 = rec(0, 1, offset, 0,true, n2);
        return res2 - res1;

    }
};