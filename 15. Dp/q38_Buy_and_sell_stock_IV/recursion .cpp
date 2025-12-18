class Solution {
public:
int rec(int i, int k,  int cur, vector<int>& prices, int n){
    if(i == n || k == 0) return 0;
    int profit = 0;
     if( cur == 0) profit = max(rec(i+1, k, 0, prices,n) , rec(i+1, k, 1, prices,n) - prices[i]);
else profit=  max(rec(i+1, k-1, 0,  prices,n) + prices[i] , rec(i+1, k, 1, prices,n)) ;
    return profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        return rec(0, k, 0, prices,n);
    }
};