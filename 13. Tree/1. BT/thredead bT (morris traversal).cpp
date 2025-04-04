vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>inorder;
    TreeNode *cur = root;
    while(cur!= NULL){
        if(cur->left ==NULL){inorder.push_back(cur->data);
        cur = cur->right;
        }
        else{
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev -> right;

            }
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }else{
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur= cur->right;
            }
        }
    }
    return inorder;
}