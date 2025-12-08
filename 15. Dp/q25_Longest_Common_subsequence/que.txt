class Solution {
public:
    int rec(string &a, string &b, int i, int j, int n, int m){
        if(i == n || j == m) return 0;
        int cnt = (a[i] == b[j]);
        return max({cnt + rec(a, b, i+1, j+1, n, m), rec(a, b, i+1, j, n, m), rec(a, b, i, j+1, n, m), rec(a, b, i+1, j+1, n, m)} );
    }
    int longestCommonSubsequence(string text1, string text2) {
        return rec(text1, text2, 0, 0, (int)text1.size(), (int)text2.size());
    }
};