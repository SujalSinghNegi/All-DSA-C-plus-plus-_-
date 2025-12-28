#include <bits/stdc++.h>
using namespace std;

void build(int ind, int low, int high, int *seg, int *arr){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2*ind+1, low, mid, seg, arr);
    build(2*ind+2, mid+1, high, seg, arr);
    seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
}

int query(int ind, int low, int high, int l , int r, int *seg){
    if(l>high || r < low) return INT_MAX;
    if(low >= l && high <= r) return seg[ind];
    int mid = low + (high - low) / 2;
    int left = query(2*ind+1, low, mid, l, r, seg);
    int right= query(2*ind+2, mid+1, high, l, r, seg);
    return min(left, right);
}

void update(int ind, int low, int high, int i , int val, int *seg){
    if(low == high) {
        seg[ind] = val;
        return;
    }
    int mid = (low + high)/2;
    if(i<= mid){
        update(2*ind+1,low, mid, i, val, seg);
    }else update(2*ind+2, mid+1, high, i, val , seg);

    seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
}
void solve(){
    int n; cin>>n;
    int arr[n];
    for(int i= 0; i<n; i++) cin>>arr[i];
    int seg[4*n];

    build(0,0, n-1, seg, arr);
    int q; cin>>q;
    while(q--){
        int type ; cin>> type;
        if(type == 1){
        int l ,r ; cin>> l >>r;
        cout << query (0, 0, n-1, l, r, seg) << endl;
    }
        else {
            int i, val; cin>> i >> val;
            update(0, 0, n-1, i, val , seg);
            arr[i] =val;

        }
    }
}

int main(){
    solve();

    return 0;
}