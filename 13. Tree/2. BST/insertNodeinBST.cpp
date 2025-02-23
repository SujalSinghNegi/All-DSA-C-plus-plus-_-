// do the traversal like to serach in Bst. then insert node , where it could be
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=  new TreeNode(val);
         if (root == NULL) return node;
         TreeNode* temp= root;
         TreeNode* a=root;
         while(temp!= NULL){
            if(temp->val == val) break;
            a = temp;
            if(temp->val < val){
                temp= temp->right;
            }else{
                temp= temp->left;
            }
         }
         if(a->val < val) a->right = node;
         else a->left = node;
         return root;

    }
};