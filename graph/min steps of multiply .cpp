class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod = 100000;
        vector<int>dist(100000, 1e9);
        queue<pair<int,int>>q;
        q.push({0,start});
        dist[start]=0;
        int n= arr.size();
        while(!q.empty()){
            auto a= q.front();
            q.pop();
            int node= a.second;
            int steps= a.first;
           if(node==end) return steps;
            for(int i=0; i<n; i++){
                int nd=(node*arr[i])%mod;
                if(dist[nd] > steps+1){
                    dist[nd]= steps+1;
                    q.push({steps+1, nd});
                    
                }
            }
            
        }
        return -1;
    }
};