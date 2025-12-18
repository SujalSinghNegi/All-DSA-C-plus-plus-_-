class Solution {
public:
int rec(int i, int j, string &s, string &t){
    if(j == -1) return 1;
    if(i == -1) return 0;
    return rec(i-1, j, s, t) + (s[i] == t[j] ? rec(i-1, j-1, s, t): 0);
}
  
    int numDistinct(string s, string t) {
        int n= s.size(), m =t.size();
        return rec(n, m, s, t);
    }
};