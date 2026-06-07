#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define f first
#define s second
int N;
struct Node{
    int tp, mom, val, ind;
};

class Fenwick{
public:
int N; 
vector<int>bit;
Fenwick(vector<int>&a){
    int n = a.size();
    N = n+1;
    bit.resize(n+1, 0);
    for(int i = 0; i < n ; i++) update(i+1, a[i]);
}
int sum(int i){
    int ret = 0;
    while(i > 0){   
        ret +=bit[i];
         i -= i&(-i);
    }
    return ret;
}
void update(int i, int val){
    while( i < N){ // N = n + 1
        bit[i] += val;
        i += i & (-i);
    }
}
int rangeSum(int l , int r){
    return sum(r) - sum(l - 1);
}
};
void solve(){
    cin>> N;
    vector<Node>q(N);
    vector<int>ans(N, -1);
    for(int i = 0; i<N; i++){
        int tp, mom, val;
        cin>> tp >> mom >> val;
        q[i] = {tp, mom, val, i};
        // if you find a query with the value not used before then answer them = 0.
        if(tp == 3) ans[i] = -1e9;
    }
    sort(all(q), [&](Node &x1, Node &x2){
    if(x1.val == x2.val) return x1.ind < x2.ind;
    return x1.val < x2.val;

    });
    int i =0;
    int n = N;
    while(i < n){
        int curVal = q[i].val;
        int l = i, r= i;
        while(r < n && q[r].val == curVal){
            r++;
        }
        int len = r - l;
        vector<int>mov(len);
        iota(all(mov), 0);

        sort(all(mov), [&](int m1, int m2){
            return ((q[i + m1].mom) < (q[i + m2].mom));
        });
        
         for(int j = 0; j<len; j++){
            q[i + mov[j]].mom = j+1;
         }
        
         vector<int> arr(len, 0);
         Fenwick fen(arr);
        for(int j =0; j<len; j++){
           if(q[i+j].tp == 1){
            fen.update(q[i+j].mom, 1);
           }else if(q[i+j].tp == 2){
            fen.update(q[i+j].mom, -1);
           }else{
            ans[q[i+j].ind] = max(0, fen.sum(q[i+j].mom));
           }

        }
        i = r;
    }
    for(int j =0;j <N; j++){
        if(ans[j] != -1) {
            int v = max(0, ans[j]);
            cout << v << "\n";
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
