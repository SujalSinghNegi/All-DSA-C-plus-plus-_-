#include <bits/stdc++.h>
using namespace std;
#define ll long long
// for 0 <= a < b <= 10^18
 ll dp[20][2][200]= {-1};

ll rec(int ind, bool tight, int sum, string &s){
    if(s.size() == ind) return sum;
    if(dp[ind][tight][sum] != -1) return dp[ind][tight][sum];
    int limit = tight? s[ind] - '0' : 9;
    ll ans = 0;
    for(int i = 0; i<=limit; i++){
        bool newTight = tight & (i == limit);
        ans += rec(ind+1, newTight, sum + i, s);
    }
    return dp[ind][tight][sum] = ans;
}

int main(){
    int t; cin>> t;
    while(t--){
        ll a, b; cin>>a >>b;
        string n1 = to_string(a-1); // 0 to low -1
        string n2 = to_string(b);  // 0 to high
       memset(dp, -1, sizeof(dp));
        ll res1 = rec(0, 1, 0, n1);
        memset(dp, -1, sizeof(dp));
        ll res2 = rec(0, 1, 0, n2);
        cout << res2 - res1 <<endl; // low to high
    }
    return 0;
}