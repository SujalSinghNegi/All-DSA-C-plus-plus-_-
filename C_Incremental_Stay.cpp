#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<
    int,                 
    null_type,           
    less<int>,           
    rb_tree_tag,        
    tree_order_statistics_node_update> ordered_set;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define inf 1e18
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fi(i,a,n) for(int i = a; i < n; i++ )
#define fl(i,a,n) for(ll i = a; ll < n; i++)



//# include "func.h"
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const T& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void inputVector(std::vector<T>& vec, int n) {
    vec.resize(n);  
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
}
void yesno(bool cond) {
    std::cout << (cond ? "YES" : "NO") << std::endl;
}
void yes(){
    std::cout << "YES" << std::endl;
}
void no(){
    std::cout << "NO" << std::endl;
}
ll power(ll x, ll y) {
    ll res = 1;     
    x = x % mod; 
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1; 
        x = (x * x) % mod; 
    }
    return res;
}

void solve(){
  //  ll n;
  //  cin>>n;
  //  vi a(n);
  //  inputVector(a,n); 

long n, k , g;
cin >> n >> k >> g;
long mem = n/g;
ll ans;
cout<< (k*power(g, mod-2))%mod;


   
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}