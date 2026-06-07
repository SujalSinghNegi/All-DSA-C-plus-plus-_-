ll eea(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1, y =0;
        return a;
    }
    ll x1, y1;
    ll g= eea(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return g;
}
ll modinv(ll a, ll b){
    ll x, y;
    ll g = eea(a, b, x, y);
    if( g!= 1){
        return -1;
    }
    return (x%b + b) % b;
}
class Fenwick{
    public:
    vector<ll>bit;
    int n;

    Fenwick(int n){
        this->n = n;
        bit.assign(n+1, 0);
    }
    void update(ll i, ll val){
        while(i <= n){
            bit[i] += val;
            i += i & (-i);
        }
    }
    ll query(ll i){
        ll sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & (-i);
        }
        return sum;
    }
    ll rangesum(ll l, ll r){
        return query(r) - query(l -1);
    }
};