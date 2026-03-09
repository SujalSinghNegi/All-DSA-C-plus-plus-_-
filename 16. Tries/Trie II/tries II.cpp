#include <bits/stdc++.h> 
struct Node{
    Node* link[26];
    int pre =0;
    int end =0;
    bool getElement(char ch){
        return (link[ch - 'a'] != NULL);
    }
    void setElement(char ch, Node* node){
        link[ch - 'a'] = node;
    }
    Node* move(char ch){
    return link[ch -'a'];
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
       root = new Node();
    }
    void insert(string &word){
       Node* node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->getElement(word[i])){
                node->setElement(word[i], new Node());
            }
            node = node->move(word[i]);
            node->pre++;
        }
        node->end++;
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->getElement(word[i])){
                return 0;
            }
            node = node->move(word[i]);
        }
        return node->end;
    }

    int countWordsStartingWith(string &word){
       Node* node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->getElement(word[i])){
                return 0;
            }
            node = node->move(word[i]);
        }
        return node->pre;
    }

    void erase(string &word){
         Node* node = root;
        for(int i = 0; i<word.size(); i++){
            node = node->move(word[i]);
            node->pre--;
        }
        node->end--;
    }
};
