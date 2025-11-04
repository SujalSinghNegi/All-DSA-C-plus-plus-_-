

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

template <typename T>
T reverseNumber(T n);

template <typename T>
void printVector(const std::vector<T>& vec);

template <typename T>
void inputVector(std::vector<T>& vec, int n);

void yes();
void no();

ll power(ll x, ll y);
ll modInverse(ll n);
string toBinary(long long n);


// //---------------------------------------- start--------------------------------------------




void solve(){  
    int n ;
    cin>>n;
    vi a(n+1);
    fi(i,1,n+1){
        cin>>a[i];
    }
    string s;
    cin>>s;
    vi col(n+1,0);
    for(int i=1; i<=n; i++){
        if(s[i-1] == '0'){
            col[a[i]] = 1;
        }
    }
    vi vis(n+1,0);
    vi result(n+1,0);
    for(int i =1; i <= n; i++){
        if(!vis[i]){
            int cnt =0;
            int cur = i;
            while(!vis[cur]){
                vis[cur] = 1;
                if(s[cur-1] == '0'){
                    cnt++;
                }
                cur = a[cur];
            }
            result[i] = cnt;
            cur = a[i];
            while(cur != i){
                result[cur] = cnt;
                cur = a[cur];
            }
            
            
        }
    }
    for(int i =1; i <= n; i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
   
   
   
   
   
   
   
   
}




// //-------------------------------------------end----------------------------------------------


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
       int t;
       cin >> t;

                 //     int t = 1;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
  

// //-----------------------------------------------------------------------------------------------   
    

// //-------------------------------------- IP OP vector ------------------------------------------
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

// //---------------------------------- yes & no -------------------------------------------------
void yes(){
    std::cout << "YES" << std::endl;
}
void no(){
    std::cout << "NO" << std::endl;
}

 // //--------------------------------------reverse no.--------------------------------------------

template <typename T>
T reverseNumber(T n) {
    T reversed_number = 0;
    T digit = 0;

    while (n != 0) {
        digit = n % 10;

        if (reversed_number > std::numeric_limits<T>::max() / 10 || 
           (reversed_number == std::numeric_limits<T>::max() / 10 && digit > std::numeric_limits<T>::max() % 10)) {
            return 0; 
        }
        if (reversed_number < std::numeric_limits<T>::min() / 10 || 
           (reversed_number == std::numeric_limits<T>::min() / 10 && digit < std::numeric_limits<T>::min() % 10)) {
            return 0; 
        }

        reversed_number = reversed_number * 10 + digit;
        n /= 10;
    }
    return reversed_number;
}


// // ---------------------------- Mod Power & Mod Inv Function ---------------------------------------

ll power(ll x, ll y) {
    ll res = 1; 
    x = x % mod; 
    if (x == 0) return 0; 
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1; 
        x = (x * x) % mod;
    }
    return res;
}
ll modInverse(ll n) {
    return power(n, mod - 2);
}

// // --------------------------Factorials and Inverse Factorials--------------------------------------

// const ll maxn = 1e6+5;
// vector<ll>fact(maxn), infact(maxn);


// void preCompute(){
//     fact[0] = 1;
//     infact[maxn-1] = modInverse(fact[maxn-1]);
//     for(ll i = 1; i < maxn; i++){
//         fact[i] = (fact[i-1]*i)%mod;
//     }
//     for(ll i = maxn-2; i >= 0; i--){
//         infact[i] = (infact[i+1]*(i+1))%mod;
//     }
// }


// // ---------------------------Permutations (nPr) and Combinations(nCr)------------------------------



// ll nCr(ll n, ll r){
//     if(r<0 || r > n) return 0;
//     return (fact[n]*((infact[r]*infact[n-r])%mod))%mod;
// }
// ll nPr(ll n, ll r){
//     if(r<0 || r > n) return 0;
//     return (fact[n]*infact[n-r])%mod;
// }

// // -------------------------------------- Dearrangements -------------------------------------------


//  ll derangements[maxn];

// void compute_derangements() {
//     derangements[0] = 1;
//     derangements[1] = 0;
//     for (int i = 2; i < maxn; i++) {
//         derangements[i] = ((i - 1) * (derangements[i - 1] + derangements[i - 2])) % 1000000007;
//     }
// }


// //  -------------------------- decimal to binary --------------------------------------------------
string toBinary(long long n) {
    if (n == 0) return "0";
    auto val = static_cast<unsigned long long>(n);
    string binaryStr = bitset<64>(val).to_string();
    return binaryStr.substr(__builtin_clzll(val));
}

