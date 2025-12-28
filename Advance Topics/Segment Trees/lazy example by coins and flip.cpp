#include <bits/stdc++.h>
using namespace std;

struct node{
int head, tail;
 node operator +(node &other){
    return {head + other.head , tail + other.tail};
}
};

class LazySegmentTree {
    vector<node> tree;
    vector<bool> lazy;
    int n;

public:

    LazySegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 1, {0,0});
        lazy.resize(4 * n + 1,0);
    }
   // what you want
    node merge(node left, node right) {
        return left + right; 
    }

    // CHANGE THIS: Logic to apply an update to a node
    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            swap(tree[node].head, tree[node].tail);  // (+=) for range sum
            if (start != end) {
                lazy[2 * node + 1] = !lazy[2 * node + 1];  // value is adding 
                lazy[2 * node + 2] = !lazy[2 * node + 2];  // value is adding 
            }
            lazy[node] = 0;
        }
    }

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            if(arr[start] == 1) tree[node].head = 1;
            else tree[node].tail = 1;
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
            lazy[node] = !lazy[node];
           // if(lazy[node])swap(tree[node].head, tree[node].tail); // Update lazy
            push(node, start, end); // Push immediately to update tree[node]
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    node query(int node, int start, int end, int l, int r) {
        push(node, start, end); // Always push before processing

        if ( start > r || end < l) return {0,0}; // Return identity (0 for sum, INF for min)

        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        return merge(query(2 * node + 1, start, mid, l, r),
                     query(2 * node + 2, mid + 1, end, l, r));
    }

    void build(const vector<int>& arr) { build(0, 0, n - 1, arr); }
    void update(int l, int r, int val) { update(0, 0, n - 1, l, r, val); }
    node query(int l, int r) { return query(0, 0, n - 1, l, r); }
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
            
            cout << st.query(l, r).head << "\n";
        } else {
            int l, r; cin >> l >> r;
            st.update(l, r, 0);
        }
    }
    return 0;
}