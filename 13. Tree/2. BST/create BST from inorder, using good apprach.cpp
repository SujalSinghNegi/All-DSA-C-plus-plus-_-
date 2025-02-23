// create BST from inorder in a simple way
class Solution {
public:
    TreeNode* build(vector<int>&preorder, int &i, int ub){
        if(i==preorder.size() || preorder[i]>ub) return NULL;
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left= build(preorder, i, node->val);
        node->right= build(preorder, i, ub);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
       TreeNode* root = build(preorder, i, INT_MAX);
       return root;

    }
};
