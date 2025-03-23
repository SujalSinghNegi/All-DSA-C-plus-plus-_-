const long long INF= 1e18;
const int MOD =1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<roads.size(); i++){
            int a = roads[i][0];
            int b = roads[i][1];
            int w = roads[i][2];
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        set<pair<long long,int>>st;
        st.insert({0,0});
        vector<long long>dist(n, INF);
        dist[0]=0;
        vector<int>ways(n, 0);
        ways[0]=1;
        while(!st.empty()){
            auto a = *(st.begin());
            long long  wt = a.first;
            long long node = a.second;
            st.erase(a);
            for(auto it: adj[node]){
                long long  toNode = it.first;
                long long toWt = it.second;
                if(dist[toNode] > wt + toWt){
                    if(dist[toNode]!= INF)st.erase({dist[toNode], toNode});
                    dist[toNode]= wt+toWt;
                    ways[toNode]= ways[node];
                    st.insert({wt+toWt, toNode});
                }else if(dist[toNode]==wt+toWt){
                 ways[toNode]= (ways[toNode]+ ways[node])%MOD;
                }
            }
        }
        if(dist[n-1]==INF) return 0;
        return ways[n-1];
    }
};