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
