// create BST from inorder

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* createBT(vector<int>&inorder, int Is, int Ie, vector<int>&preorder, int Ps, int Pe, unordered_map<int,int>&mpp){
          if(Ps > Pe || Is > Ie) return NULL;
        Node* root = newNode(preorder[Ps]);
        int index= mpp[preorder[Ps]];
        int numsLeft= index - Is;
        root->left = createBT(inorder, Is, index-1, preorder, Ps+1, Ps+numsLeft, mpp);
        root->right= createBT(inorder, index+1, Ie, preorder, Ps+numsLeft+1, Pe, mpp);
        return root;
    }
    Node* Bst(int pre[], int size) {
        // code here
        vector<int>preorder(size);
          unordered_map<int,int>mpp;
        for(int i=0; i<size; i++){
            preorder[i]=pre[i];
        }
        vector<int>inorder=preorder;
        sort(inorder.begin(), inorder.end());
        for(int i=0; i<size; i++){
            mpp[inorder[i]]=i;
        }
      
        Node* root= createBT(inorder, 0, size-1, preorder, 0, size-1, mpp);
        return root;
    }
};