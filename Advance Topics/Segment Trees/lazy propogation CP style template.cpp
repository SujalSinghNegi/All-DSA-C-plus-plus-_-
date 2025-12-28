#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
    vector<long long> tree, lazy;
    int n;

public:
    LazySegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);
    }

    long long merge(long long left, long long right) {
        return left + right; 
    }

    // CHANGE THIS: Logic to apply an update to a node
    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, arr);
        build(2 * node + 2, mid + 1, end, arr);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int start, int end, int l, int r, int val) {
        push(node, start, end); // Always push before processing
        
        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            lazy[node] += val; // Update lazy
            push(node, start, end); // Push immediately to update tree[node]
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    long long query(int node, int start, int end, int l, int r) {
        push(node, start, end); // Always push before processing

        if (start > end || start > r || end < l) return 0; // Return identity (0 for sum, INF for min)

        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        return merge(query(2 * node + 1, start, mid, l, r),
                     query(2 * node + 2, mid + 1, end, l, r));
    }

    void build(const vector<int>& arr) { build(0, 0, n - 1, arr); }
    void update(int l, int r, int val) { update(0, 0, n - 1, l, r, val); }
    long long query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

int main() {
    
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    LazySegmentTree st(n);
    st.build(arr);

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r; cin >> l >> r;
            
            cout << st.query(l, r) << "\n";
        } else {
            int l, r, val; cin >> l >> r >> val;
            st.update(l, r, val);
        }
    }
    return 0;
}