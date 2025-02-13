int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ceil= -1;
    Node* temp = root;
    while(temp!=NULL){
        if(temp->data == input) return input;
        if(temp->data > input){
            ceil= temp->data;
            temp= temp->left;
        }else{
            temp= temp->right;
        }
    }
    return ceil;
    // Your code here
}