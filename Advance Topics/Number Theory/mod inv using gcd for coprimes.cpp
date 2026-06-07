#include <bits/stdc++.h>
#define ll long long


ll eea(ll a, ll b, ll &x,ll &y){
      if(b == 0){
          x = 1, y = 0;
          return a;
      }
      ll x1, y1;
      ll g= eea(b, a % b, x1, y1);
      x = y1;
      y = x1 - y1 * (a / b);
      return g;
      
  }
  
ll modInv(ll a, ll m){
    ll x, y;
    ll g = eea(a, m, x, y);
    if(g != 1){
        return -1;  // it means the a and b are not coprime.. this method is only for if a and b are coprime...
    }
    return ( x % m + m ) % m; // as the number can be any +ve or -ve
}