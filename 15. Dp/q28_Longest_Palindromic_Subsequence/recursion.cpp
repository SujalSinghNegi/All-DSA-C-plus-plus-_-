class Solution {
public:
int rec(int  l , int r, string &s ){
    if(l > r) return 0;
    if(l == r) return 1;
    int nr = r;
    while(nr > l && s[l] != s[nr])nr--;
    int cnt = 0;
    if(nr  > l && s[l] == s[nr]) cnt = 2+rec(l+1, nr -1, s);
    return max({cnt, rec(l+1, r, s), rec(l, r-1, s)});

}
    int longestPalindromeSubseq(string s) {
        int n= s.size();
        return rec(0, n-1, s);
    }
};