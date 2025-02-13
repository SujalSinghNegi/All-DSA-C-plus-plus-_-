// check the bt is bst
 bool check(Node* node, int low, int high){
        if(node==NULL) return true;
        if(!(node->data > low && node->data < high)) {
            return false;
        }
       return check(node->left, low, node->data)&&check(node->right, node->data, high);
        
        
    }
    bool isBST(Node* root) {
        // Your code here
        return check(root, INT_MIN, INT_MAX );
    }
};