 // https://lightoj.com/problem/investigation


 /*
  Investigation
2 seconds
64 MB
Medium
LOJ-1068
Udebug Debug

An integer is divisible by 3 if the sum of its digits is also divisible by 3. For example, 3702 is divisible by 3 and 12 (3+7+0+2) is also divisible by 3. This property also holds for the integer 9.

In this problem, we will investigate this property for other integers.
Input

Input starts with an integer T (≤ 200), denoting the number of test cases.

Each case contains three positive integers A, B and K (1 ≤ A ≤ B < 231 and 0 < K < 10000)>.
Output

For each case, output the case number and the number of integers in the range [A, B] which are divisible by K and the sum of its digits is also divisible by K.
Sample
Input 	Output

3
1 20 1
1 20 2
1 1000 4
	
Case 1: 20
Case 2: 5
Case 3: 64


*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll k;
ll dp[10][2][100][100];
ll rec(int ind, bool tight, int sum, int rem, string &s){
    if(ind == (ll)s.size()) return ((rem % k ==0) && (sum % k == 0));
    if(dp[ind][tight][sum][rem] != -1) return dp[ind][tight][sum][rem];
    
    int limit = tight? s[ind] - '0' : 9;
    ll ans = 0;
    for(int d = 0; d<= limit; d++){
    ans+= rec(ind+1, ((d == limit)&tight), sum + d,
             ( rem + ((ll)d*(ll) pow(10, (int)s.size() - 1- ind) )%k)%k,
              s);
    }
    return dp[ind][tight][sum][rem] = ans;
}
void solve(){
ll a, b, c;
cin>>a>>b>>c;
    k=c;
    if(c > 100) {
        cout << 0 << endl;
        return;
    }
    string n1 = to_string(a-1);
    string n2 = to_string(b);
        memset(dp, -1, sizeof(dp));
    ll res1 = rec(0,1,0,0,n1); 
        memset(dp, -1, sizeof(dp));
    ll res2 =  rec(0,1,0,0,n2); 
   
    cout << res2 - res1 <<endl;
    
    
}

int main() {
    int t; cin>>t;
   for(int i = 1; i<=t; i++){
       cout << "Case " << i << ": ";
    solve();
    }
    return 0;
}
