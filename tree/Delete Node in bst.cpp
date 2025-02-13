// delete node in BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root ==NULL) return NULL;
        if(root->val == key){
            return deleteTheRootCase(root);
        }
        TreeNode * dummy = root;
        while(root!= NULL){
            if (root->val > key){
                if(root->left && root->left->val==key){
                    root->left = deleteTheRootCase(root->left);
                }else{
                    root= root->left;
                }
            }else{
                if(root->right && root->right->val==key){
                    root->right= deleteTheRootCase(root->right);
                }else{
                    root= root->right;
                }

            }
        }
        return dummy;
    }
    TreeNode* deleteTheRootCase(TreeNode* root){
        if(root->left ==NULL) return root->right;
        if(root->right ==NULL)return root->left;
        TreeNode* rightChild= root->right;
        TreeNode* lastChild= findRightest(root->left);
        lastChild->right= rightChild;
        return root->left;
    }
    TreeNode* findRightest(TreeNode* root){
        if(root->right ==NULL) return root;
        return findRightest(root->right);
    }
};