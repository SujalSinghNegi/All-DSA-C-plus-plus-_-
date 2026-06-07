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