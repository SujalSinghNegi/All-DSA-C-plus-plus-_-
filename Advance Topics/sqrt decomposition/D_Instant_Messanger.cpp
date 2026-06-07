

/**
 * author:  Sujal Singh Negi
 * created: 02.05.2026 22:02:39
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long

ll mod = 1000000007;
// ll mod = 998244353;

// ---------------------- Defines & Typedefs ----------------------
#define ull unsigned long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

#define f first
#define s second
#define sz(x) (int)x.size()
#define fi(i,a,n) for(int i = a; i < n; i++ )
#define fl(i,a,n) for(ll i = a; i < n; i++) 
#define add(x) accumulate(x.begin(), x.end(), 0LL)
#define mi(x) *min_element(x.begin(), x.end())
#define ma(x) *max_element(x.begin(), x.end())

// ---------------------- Generic I/O Templates ----------------------

// Forward declarations
template<typename T> void read(T& x);
template<typename T1, typename T2> void read(pair<T1, T2>& p);
template<typename T> void read(vector<T>& v);
template<typename T> void print(const T& x);
template<typename T1, typename T2> void print(const pair<T1, T2>& p);
template<typename T> void print(const vector<T>& v);

// READ Functions
template<typename T> void read(T& x) { cin >> x; }
template<typename T1, typename T2> void read(pair<T1, T2>& p) { read(p.first); read(p.second); }
template<typename T> void read(vector<T>& v) { for(auto& x : v) read(x); }
template<typename T, typename... Args> void read(T& t, Args&... args) { read(t); read(args...); }

// PRINT Functions
template<typename T> void print(const T& x) { cout << x << ' '; }
template<typename T1, typename T2> void print(const pair<T1, T2>& p) { print(p.first); print(p.second); }
template<typename T> void print(const vector<T>& v) { for(const auto& x : v) print(x); cout << endl; }
template<typename T, typename... Args> void print(const T& t, const Args&... args) { print(t); print(args...); }
// Print with newline at the end (for single variables)
template<typename... Args> void println(const Args&... args) { print(args...); cout << endl; }


// int and long long are supported, use it like unordered_map<int,int,custom_hash>mpp , or like set<int, custom_hash>st; 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


// ---------------------- Bit Manipulation (C++20 / GCC) ----------------------
// These macros work on 64-bit integers (long long) safely
#define popcount(x) __builtin_popcountll(x)  // Count set bits
#define clz(x) __builtin_clzll(x)            // Count leading zeros
#define ctz(x) __builtin_ctzll(x)            // Count trailing zeros
#define parity(x) __builtin_parityll(x)      // Parity (1 = odd set bits, 0 = even)
#define bit_ceil(x) (1LL << (64 - clz(x - 1))) // Round up to next power of 2 (requires x > 1)
#define msb(x) 63 - clz(x)
// ---------------------- Utilities (chmin/chmax) ----------------------
template<class T> bool chmin(T &a,T b){if(b<a){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return 1;}else return 0;}

// ---------------------- Modular Arithmetic (mint) ----------------------
struct mint {
    static constexpr int m = 998244353; // Change to 1000000007 if needed
    int x;
    mint() : x(0){}
    mint(long long x_):x(x_ % m){if (x < 0) x += m;}
    int val(){return x;}
    mint &operator+=(mint b){if ((x += b.x) >= m) x -= m; return *this;}
    mint &operator-=(mint b){if ((x -= b.x) < 0) x += m; return *this;}
    mint &operator*=(mint b){x= (long long)(x) * b.x % m; return *this;}
    mint pow(long long e) const {
        mint r = 1,b =*this;
        while (e){
            if (e & 1) r *= b;
            b *= b;
            e >>= 1;
        }
        return r;
    }
    mint inv(){return pow(m - 2);}
    mint &operator/=(mint b){return *this *= b.pow(m - 2);}
    friend mint operator+(mint a, mint b){return a += b;}
    friend mint operator-(mint a, mint b){return a -= b;}
    friend mint operator/(mint a, mint b){return a /= b;}
    friend mint operator*(mint a, mint b){return a *= b;}
    friend bool operator==(mint a, mint b){return a.x == b.x;}
    friend bool operator!=(mint a, mint b){return a.x != b.x;}

    // I/O Overloads for generic compatibility
    friend istream& operator>>(istream& is, mint& a) { long long t; is >> t; a = mint(t); return is; }
    friend ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
};




// ---------------------- Utilities ----------------------

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

ll revNum(ll n) {
    ll rev = 0;
    while (n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

ll power(ll x, ll y) {
    ll res = 1; x = x % mod; 
    if (x == 0) return 0; 
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y = y >> 1; x = (x * x) % mod;
    }
    return res;
}

ll modInverse(ll n) { return power(n, mod - 2); }

string toBinary(ll n) {
    if (n == 0) return "0";
    auto val = static_cast<unsigned ll>(n);
    string binaryStr = bitset<64>(val).to_string();
    return binaryStr.substr(__builtin_clzll(val));
}

ll btoInt(string &s) { return stoll(s, nullptr, 2); }

//phi(n) = n * ( 1 - 1 / p1) * (1 - 1 / p2) ... till all primes.. of n
//phi(M) = M - 1 for M is prime
ll phi(ll n){
    ll res = n;
    for(ll i = 2; i*i <=n; i++){
        if(n%i == 0){
            while(n%i == 0)  n/=i;
            res-= res/i;
        }
    }
    if(n > 1){
        res-= res/n;
    }
    return res;
}


// // ------------------Factorials and Inverse Factorials------------------------

// const ll maxn = 1e6+5; 

// vector<ll>fact(maxn), infact(maxn);
// dont forget to add the preCompute() in the int main() 
// void preCompute(){
//     fact[0] = 1;
//     for(ll i = 1; i < maxn; i++){
//             fact[i] = (fact[i-1]*i)%mod;
//         }
//         infact[maxn-1] = modInverse(fact[maxn-1]);
//     for(ll i = maxn-2; i >= 0; i--){
//         infact[i] = (infact[i+1]*(i+1))%mod;
//     }
// }


// // ----------------Permutations (nPr) and Combinations(nCr)-----------------------
// ll nCr(ll n, ll r){
//     if(r<0 || r > n) return 0;
//     return (fact[n]*((infact[r]*infact[n-r])%mod))%mod;
// }
// ll nPr(ll n, ll r){
//     if(r<0 || r > n) return 0;
//     return (fact[n]*infact[n-r])%mod;
// }

// -------------------------- Dearrangements -------------------------------
//  ll derangements[maxn];
// void compute_derangements() {
//     derangements[0] = 1;
//     derangements[1] = 0;
//     for (int i = 2; i < maxn; i++) {
//         derangements[i] = ((i - 1) * (derangements[i - 1] + derangements[i - 2])) % 1000000007;
//     }
// }



// ------------------------------ Solution ---------------------------

const int maxn = 50005;
const int b = 350; // sqrt(maxn)
unordered_set <int, custom_hash> adj[maxn];
vector<int>heavy_friend[maxn];

vi on(maxn, 0);
vi cnt(maxn, 0);
vi heavy(maxn, 0);
// vi is_hon(maxn, 0);
// when someone become the celeb/ heavy. it must remove the data of on / off count from all the friends because now they will now treat him seperately for ever

void make_heavy(int node){
    bool status = on[node] && (!heavy[node]);
    heavy[node] = 1;
    for(auto child: adj[node]){
        if(status) cnt[child]--;
        heavy_friend[child].pb(node);
    }
}
void addf(int u, int v){
    adj[u].insert(v);
    adj[v].insert(u);
    if(heavy[u]){
        heavy_friend[v].push_back(u);
    }else if(adj[u].size() == b + 1){
         if(on[u]) cnt[v]++; // because the make heavy will also dec the cnt for u, now adding it making it null effect.
        make_heavy(u);
    }
    else{
       if(on[u]) cnt[v]++;
    }
     if(heavy[v]){
        heavy_friend[u].push_back(v);
    }else if(adj[v].size() == b + 1){
         if(on[v]) cnt[u]++;
        make_heavy(v);
    }else{
       if(on[v])cnt[u]++;
    }

}
void remh(int node, int h){
    int s= heavy_friend[node].size();
    for(int i = 0; i<s; i++){
        if(heavy_friend[node][i] == h){
            swap(heavy_friend[node][i], heavy_friend[node][s -1]);
            heavy_friend[node].pop_back();
            return;
        }
    }
}
void delf(int u, int v){
    adj[u].erase(v);
    adj[v].erase(u);
    if(heavy[u]){
        remh(v, u);
    }else{
        if(on[u])cnt[v]--;
    }
     if(heavy[v]){
        remh(u, v);
    }else{
        if(on[v])cnt[u]--;
    }

}
int countf(int node){
   int ans = 0;
   for(auto child: heavy_friend[node]){
    if(on[child]) ans++;
   }
   return cnt[node] + ans;
}
void onf(int node){
    on[node] = 1;
    if(heavy[node]) return;
    for(auto it : adj[node]){
       cnt[it]++;
    }
}
void off(int node){
    on[node] = 0;
    if(heavy[node])  return;
    for(auto it : adj[node]){
       cnt[it]--;
    }
}


void solve(){
 
int n, m, q;
cin >> n >> m >> q;
int o;
cin>> o;
for(int i = 0; i<o; i++){
    int x; cin >> x;
    on[x] = 1;
}
for(int i = 0; i<m; i++){
    int u, v; cin>> u >> v;
  addf(u, v);
}

for(int i =0; i<q; i++){
    char tp; cin>> tp;
    if(tp == 'A'){
        int u, v; cin>> u >> v;
        addf(u, v);
    }else if(tp == 'C'){
        int x; cin>> x;
        cout << countf(x) << "\n";
    }else if(tp == 'O'){
        int x; cin>> x; 
        onf(x);
    }else if(tp == 'F'){
        int x; cin>> x;
        off(x);
    }else if(tp == 'D'){
        int u, v; cin>> u >> v;
        delf(u, v);
    }
}

   
}

// ---------------------- Main ----------------------

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;

 
  //  cin >> t;  //remove 
    

    while (t--) {
        solve();
    }
    
    return 0;
}