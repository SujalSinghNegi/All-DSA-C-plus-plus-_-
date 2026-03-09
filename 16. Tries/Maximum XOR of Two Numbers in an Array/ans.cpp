struct Node{
    Node* link[2] ={NULL};
    bool end =0;
    bool get(bool f){
        return (link[f] != NULL);
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
        for(int i =30; i>=0; i--){
            bool f = (x & (1LL<<i));
            if(!node->get(f)){
                Node *cur = new Node();
                node->link[f] = cur;
            }
            node = node->link[f];
        }
        node->end = 1;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n  = nums.size();
        Trie trie;
        for(int i = 0; i<n; i++){
            trie.insert(nums[i]);
        }
        int maxa =0;
        for(int num : nums){
        Node* node = trie.root;
        int ans = num;
            for(int i = 30; i>=0; i--){
                if(num & ( 1LL << i)){
                    if(node->get(0)) {
                    node = node->link[0] ; 
                    }
                    else {
                    node = node->link[1];
                     ans -= ( 1<< i);
                     }
                }else{
                    
                    if(node->get(1)) {
                    node = node->link[1] ; 
                    ans += ( 1<< i);
                    }
                    else {
                        node = node->link[0] ;
                     }
                }
            }
            maxa = max(maxa, ans);
        }
        return maxa;
    }
};