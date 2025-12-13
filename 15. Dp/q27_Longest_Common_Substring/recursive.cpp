int rec(int i , int j, string &s1, string &s2, int &maxa){
    if(i < 0 || j < 0) return 0; 
    int cnt = 0;
    if(s1[i] == s2[j]){
        cnt = 1 + rec(i-1, j-1 , s1, s2, maxa);
    }
    rec(i, j-1, s1, s2, maxa);
    rec(i-1, j, s1, s2, maxa);
     maxa =max(cnt, maxa);
     return cnt;
}
int LCSubStr(string &s1, string &s2)
{
    int maxa = 0;
    int n= s1.size(), m = s2.size();
   rec(n-1, m-1, s1,s2, maxa);
return maxa;
}
