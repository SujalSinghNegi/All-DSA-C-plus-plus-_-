// serialize and deserialize Binary tree
#include <bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class Codec {
    public:
    string serialize(TreeNode* root){
        if(root == NULL){
            return "";
        }
        string s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp= q.front();
            q.pop();

            if(temp==NULL)s+="#,";
            else{
                s+=to_string(temp->val)+',';
                q.push(temp->left);
                q.push(temp->right);

            }
        }
        return s;
       
    }
    TreeNode* deserialize(string data){
        if(data.size() == 0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* temp= q.front();
            q.pop();

            getline(s, str, ',');
            if(str=="#"){
                temp->left= NULL;
            }else{
                TreeNode* node = new TreeNode(stoi(str));
                temp->left = node;
                q.push(node);
            }
             getline(s, str, ',');
            if(str=="#"){
                temp->right= NULL;
            }else{
                TreeNode* node = new TreeNode(stoi(str));
                temp->right = node;
                q.push(node);
            }

        }
        return root;     
       
    }

};
