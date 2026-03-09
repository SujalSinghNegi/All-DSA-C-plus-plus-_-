
struct Node{
    Node* link[26] = {nullptr};
    int pre =0;
    int end= 0;
    bool getElement(char ch) {
        return (link[ch -'a'] != nullptr);
    }
    void setElement(char ch, Node* node){
        link[ch - 'a'] = node;
    }
};
class Trie{
    public:
    Node *root;
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node *node = root;
        for(int i =0; i<word.size(); i++){
            if(!node->getElement(word[i])){
                node->setElement(word[i], new Node());
            }
            node->pre++;
            node = node->link[word[i] - 'a'];
        }
        node->end++;
    }
    
     
};
string res;
int dfs(Node *root, string &ans){
    int maxa = ans.size();
    for(int i = 0; i<26; i++){
    Node *node = root->link[i];
    if(node != nullptr && node->end >=1) {
        ans.push_back(char(i + 'a'));
    int cur= 1 + dfs(node, ans);
      if(res.size() < ans.size())  res = ans;
        ans.pop_back();
    }
    }
    return maxa;
}
class Solution {
    public:
    string longestValidWord(vector<string>& words) {
        Trie trie;
        for(string &s: words){
            trie.insert(s);
        }
        string s;
        res = "";
        dfs(trie.root, s);
        return res;
        
    }
};
