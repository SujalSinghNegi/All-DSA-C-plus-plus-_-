struct Node{
    Node *link[2] = {NULL};
    bool end = 0;
    bool get(bool f){
        return (link[f] != NULL) ;
    }
};
class Trie{
    public:
    Node *root;
    Trie(){
        root = new Node();
    }
     void insert(int x){
        Node *node = root;
        for(int i = 30; i>=0; i--){
            bool f = ((1 << i) & x);
            if( !node->get(f)){
                Node *cur = new Node();
                node->link[f] = cur;
            }   
            node = node->link[f];
        }
        node->end  =1;
    }

};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        int m = q.size();
        vector<int>order(m);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int &a, int &b){
            return (q[a][1] < q[b][1]);
        });
        sort(nums.begin(), nums.end());
        Trie trie;
        vector<int>ans(m);
        int n = nums.size();
        int j = 0;
        for(int i = 0; i<m; i++){
            int ind = order[i];
            while(j < n && q[ind][1] >= nums[j]){
                trie.insert(nums[j++]);
            }
            int num = q[ind][0];
            Node *node = trie.root;
                   if(j == 0){
                     ans[ind] = -1;
                       continue;
                   }
            for(int bit = 30; bit >= 0; bit--){
                if(q[ind][0] & ( 1LL << bit)){
                    if(node->get(0)){
                        node= node->link[0];
                    }else{
                        node = node->link[1];
                        num -= (  1 << bit);
                    }
                }else{
                      if(node->get(1)){
                        node= node->link[1];
                        num += ( 1LL << bit);
                    }else
                        node = node->link[0];    
                }     
            }
            ans[ind] = num;
        }
       return ans;
    }
};