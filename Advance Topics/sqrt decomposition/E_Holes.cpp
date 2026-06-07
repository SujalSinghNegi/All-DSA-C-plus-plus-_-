#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
const int B = 350;
int a[maxn];
int next_hole[maxn];
int jump[maxn];
int n, m;

void recal(int ind){
    int cur = (ind - 1)/ B;
    if(a[ind] + ind > n) next_hole[ind]= ind, jump[ind] = 1;
    else if(a[ind] + ind > cur * B + B) next_hole[ind]= a[ind] + ind, jump[ind] = 1;
    else{
        next_hole[ind] = next_hole[a[ind] + ind];
        jump[ind] = jump[a[ind] + ind] + 1;
    }
}
void upd(int ind, int val){
    a[ind] = val;
    int cur = (ind - 1) / B;
    for(int i =ind; i>=cur * B + 1; i--){
        recal(i);
    }
   
}
void query(int ind){
    int j = 0;
    while(true){
        j += jump[ind];
        int cur = (ind - 1) / B;
        if(next_hole[ind] <= cur * B + B){
            cout << next_hole[ind] << " " << j << "\n";
            return;
        }
        ind = next_hole[ind];
    }
}

void solve(){
    cin >> n >> m;
    for(int i =1; i<=n; i++) cin>> a[i];
    for(int i = n; i>=1; i--){
        recal(i);
    }
    for(int i = 1; i<=m; i++){
        int tp; cin>> tp;
        if(tp == 0){
            int ind, val; cin>> ind >> val;
            upd(ind, val);
        }else{
            int ind; cin>> ind;  
            query(ind);         
        }
    }
   
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1; 
   // cin >> t; // remove it
    while(t--){ 
    solve();
    }
    return 0;
}
