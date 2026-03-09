
struct Node{
    Node *link[26];
    bool end = 0; 
    bool getElement(char ch){
        return (link[ch -'a'] != NULL);
    }
    void setElement(char ch, Node *node){
        link[ch - 'a'] = node;
    }
};
class Trie{
    public:
    Node *root;
   // string word;
    Trie(){
        root = new Node();
        // word = s;
    }
bool insert(Node *cur, char ch){
    //Node *node = root;
    bool ans = 0;
    if(cur->link[ch  - 'a'] == NULL) {
        ans = 1;
        Node *node = new Node();
        cur->link[ch - 'a'] = node;
    }
    return ans;
}
};
class Solution {
  public:
    int countSubs(string& s) {
        int n = s.size();
        int ans =0;
        Trie trie;
        for(int i= 0; i<n; i++){
            Node* node = trie.root;
            for(int j= i; j<n; j++){
              ans += trie.insert(node, s[j]);
              node = node->link[s[j] - 'a'];
            }
        }
        return ans;
    }
};