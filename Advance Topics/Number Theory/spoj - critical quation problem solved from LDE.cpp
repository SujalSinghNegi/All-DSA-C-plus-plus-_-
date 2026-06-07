#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll eea(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g= eea(b, a%b, x1,  y1);
     x = y1;
     y = x1 - y1 * ( a/ b);
    return g;
}

bool LDE(ll &x, ll &y, ll a, ll b, ll c){
    ll g= eea(abs(a), abs(b), x, y);
    if(c % g != 0){
        return false;
    }
    ll k = c/g; 
    x*= k;
    y*= k;
    if(a < 0) x *= -1;
    if(b < 0) y *= -1;

    return true;
}
int main() {
	// your code goes here
	ll t; cin>> t;
    for(int i = 1; i<=t; i++){
		ll a, b, c; cin>> a >> b >> c;
		ll x, y;
		cout << "Case " << i <<": ";
		if(LDE(x, y, a, b, c)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}