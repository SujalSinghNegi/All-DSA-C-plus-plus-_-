class SegTree{
    public:
    int n;
    vector<int>seg;
    SegTree(int n){
        this->n = n;
        seg.resize(4*n + 1);
    }
    void build(int ind, int low, int high, vector<int>&arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = seg[2*ind+1]+ seg[2*ind + 2];
    }
    
    int query(int ind, int low, int high, int l, int r){
        if(high<l || low>r) return 0;
        if(low >=l && high <= r) return seg[ind];
        
        int mid = low + (high - low) /2;
        int left = query(2*ind+1, low , mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return left+right;
    }
    void update(int ind, int low, int high, int i , int val){
        if(low == high){
            seg[ind]--;
            return;
        }
        int mid = low + (high - low)/ 2;
        if(i<=mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i , val);
        seg[ind] = seg[2*ind+1]+ seg[2*ind+2];
    }
    int query(int l,int r){
        return query(0, 0, n-1, l, r);
    }
    void build(vector<int>&arr){
        build(0, 0, n-1, arr);
    }
};

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        vector<int>freq(1e4+1, 0);
        for(int x: arr){
            freq[x]++;
        }
        SegTree seg(1e4+1);
        seg.build(freq);
        int ans = 0;
        for(int x:arr){
            seg.update(0, 0, 1e4, x, 0);
            ans += seg.query(1, x-1);
        }
        return ans;
    }
};




