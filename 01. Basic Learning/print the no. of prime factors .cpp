
vector<int> primeFactors(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i); 
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) ans.push_back(n);
    return ans;
}

vector<pair<int,int>> primeFactorsWithPower(int n) {
    vector<pair<int,int>> ans;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int p =0;
            while (n % i == 0) {
                n /= i;
                p++;
            }
            ans.push_back({i,p}); 
        }
    }
    if (n > 1) ans.push_back({n,1});
    return ans;
}