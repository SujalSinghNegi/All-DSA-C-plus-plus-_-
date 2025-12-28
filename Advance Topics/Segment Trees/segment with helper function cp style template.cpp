#include <bits/stdc++.h>
using namespace std;



class SegTree {
public:
    int n;
    vector<int> seg;

    SegTree(int n) {
        this->n = n;
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        if (high < l || low > r) return INT_MAX;
        if (low >= l && high <= r) return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    
   
    void build(vector<int>& arr) {
        build(0, 0, n - 1, arr);
    }
};