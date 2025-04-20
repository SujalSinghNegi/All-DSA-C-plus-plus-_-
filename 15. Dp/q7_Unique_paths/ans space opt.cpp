class Solution {
public:
    int uniquePaths(int m, int n) {
    vector<int>opt(n, 1);
        for(int i=1; i<m; i++){
            int left =1;
            for(int j=1; j<n; j++){
                if(i==0&& j==0)continue;
                int up = opt[j];
                opt[j]= up+left;
                left = opt[j];
            }
        }
        return opt.back();

    }
};