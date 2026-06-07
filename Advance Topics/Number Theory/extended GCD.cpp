
#define ll long long
class Solution {
  public:
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
  
    vector<ll> gcd(ll a, ll b) {
        // code here
        ll x, y;
        ll g= eea(a, b, x, y);
        return {g, x, y};
    }
};