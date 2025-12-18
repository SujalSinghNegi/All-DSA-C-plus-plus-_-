class Solution {
public:
int rec(int i , int j, string &s, string &p){
    if(i == -1) return  (j == -1 ||(p[j] == '*' && rec(i, j-1, s, p)));
    if(j == -1) return (i == -1);
    if(s[i] == p[j] || p[j] == '?') return rec(i-1, j-1, s, p);
   if(p[j] != '*') return 0;
   return (rec(i-1, j, s, p) | rec(i-1, j-1, s, p)) | rec(i, j-1, s, p);
}
    bool isMatch(string s, string p) {
        int n =s.size(), m = p.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        return rec(n-1, m-1, s, p);
    }
};