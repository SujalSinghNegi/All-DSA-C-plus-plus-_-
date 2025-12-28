#include <bits/stdc++.h>
using namespace std;

class ST {
    public:
    vector<long long>seg, lazy;
    ST(int n){
        seg.resize(4*n + 1);
        lazy.resize(4*n + 1, 0);
    }
    void build(int ind, int low, int high, vector<int>&arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
     void update(int ind, int low, int high, int l, int r, int val){
        // for all the cases this will be done 
        // if there was previous updates remaning or say lazy node != 0, then just update it also pass on the lazy to the childrens if any
        if(lazy[ind] != 0){
            seg[ind] += (long long)(high - low + 1) * lazy[ind];
            if(high != low){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] =0;
        }
        // no overlap return 
        if(high < l || low > r) return; 

        // complete overlap
        // update the current node ,and updates the lazy node to the children if any
        if(low >= l && high <= r){
            seg[ind] += (long long)(high - low + 1) * val;
            if(high != low){
                lazy[2*ind +1] += val;
                lazy[2*ind+2]  += val;
            }
            return;
        }
       
        // partial overlap
       int mid = low + (high - low) / 2;
        update(2*ind + 1, low, mid, l, r, val);
        update(2*ind +2, mid+1, high, l, r, val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    long long query(int ind, int low, int high, int l , int r){
        // always do the step 0: updates if any updates, or say if lazy node is not zero
        if(lazy[ind] != 0){
            seg[ind] += (long long)(high - low + 1) * lazy[ind];

            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
       if(high < l || low > r ) return 0;
       if(low >= l && high <= r){
        return seg[ind];
        
       }

       int mid = low + (high - low) / 2;
       long long left = query(2*ind + 1, low, mid, l, r);
       long long right = query(2*ind +2, mid+1, high, l, r);
       return left + right;
    }
   
};

int main() {

    int n; cin>>n;
    vector <int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    ST st(n);
    st.build(0, 0, n-1, arr);
    int q; cin>> q;
    while(q--){
        int type;  cin>>type;
        if(type == 1) {
            int l , r ; cin>>  l >> r;
            cout << st.query(0, 0,n-1, l, r) << endl;

        }else{
            int l , r , val; cin >> l >>r >>val;
            st.update(0, 0, n-1, l, r, val);
        }
    }
    return 0;
}