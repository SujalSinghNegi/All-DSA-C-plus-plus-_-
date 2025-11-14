// for single number
class Div1{
    public:
    vector<int>d;
    Div1(int n){
        int sqn = sqrt(n);
        for(int i =1; i<= sqn; i++){
            if(n%i ==0){
                d.push_back(i);
                if(i!= n/i)d.push_back(n/i);
            }
        }
        sort(d.begin(), d.end());
    }
};

// precompute divisors for the range of number
class DivN{
    public:
int MAXN ;
vector<vector<int>> d;

DivN(int n) {
   this->MAXN = n+2;
   d.resize(MAXN);
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            d[j].push_back(i);
        }
    }
}
};
