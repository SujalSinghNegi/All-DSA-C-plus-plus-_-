class Solution {
  public:
    string findOrder(vector<string> dict, int k) {
        // code here
        int n= dict.size();
        vector<char>adj[k];
        for(int i=0; i<n-1; i++){
            int m= dict[i].size();
            int p=dict[i+1].size();
            int j=0;
            while(j<m && j<p){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
                j++;
            }
        }
        // now from here use any method to check the cycle or not
        vector<int>indegree(k,0);
        for(int i=0; i<k; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
       queue<int>q;
        for(int i=0; i<k; i++){
            if(indegree[i]==0)q.push(i);
        }
        string topo;
        while(!q.empty()){
            int node= q.front();
            q.pop();
           topo+=node+'a';
            for(int bt:adj[node]){
                indegree[bt]--;
                if(indegree[bt]==0) q.push(bt);
            }
        }
        if(topo.size()==k) return topo;
        else return "";
    }
};