class Solution {
public:
int rec(int i , int j, string &a, string &b){
    if(j == -1) return i+1;
    if(i == -1) return j+1;

    return min({
        1 +rec(i, j-1, a, b),
         1+rec(i-1, j, a, b),
          (a[i] != b[j]) +  rec(i-1, j-1, a, b)
     });
}
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        return rec(n, m , a, b);
    }
};