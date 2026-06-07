#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll eea(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll g = eea(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * ( a/ b);
    return g;
}
bool LDE(ll &x, ll&y, ll a, ll b, ll c, ll &g){
    g= eea(abs(a), abs(b), x, y);
    if(c % g != 0){
        return false;
    }
    ll k = c / g;
    x *= k;
    y *= k;
    if( a < 0) x = -x;
    if(b < 0) y = -y;
    return true;
}

void solve(){
   ll a, b, c;
   cin >> a >> b >> c;
   ll x, y, g;
    bool f = LDE(x, y, a, b, c, g);
    if(!f) cout << "No\n";
    else{
        ll lk = ceil(double(-x * g) / b);
        ll rk = floor (double(y * g) / a);
        if(rk >= lk) cout << "Yes\n";
        else cout << "No\n";
    }
   
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1; 
  //  cin >> t; // remove it
    while(t--){ 
    solve();
    }
    return 0;
}
