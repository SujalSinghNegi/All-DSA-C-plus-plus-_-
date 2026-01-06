//902. Numbers At Most N Given Digit Set


class Solution {
public:
int dp[11][2][2] ;
vector<char>allow;
    int rec(int ind, bool tight, bool st, string &s){
        if(ind == (int)s.size()) return (!st);
        if(dp[ind][tight][st] != -1) return dp[ind][tight][st];
        int limit = tight? s[ind] - '0': 9;
        int ans = 0;
        if(st){
            ans += rec(ind+1, 0, 1, s);
        }
        for(int ch : allow){
           ch-='0';
           if(ch > limit) break;
            int newTight = tight & (ch == limit);
            ans += rec(ind+1, newTight, 0, s);
            ch -= '0';
        }
        return dp[ind][tight][st] = ans;

    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i<digits.size();i++){
            allow.push_back(digits[i][0]);
        }
        
        return rec(0,1,1,s);
    }
};