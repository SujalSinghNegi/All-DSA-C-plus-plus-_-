class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        int input = x;
    if (root == NULL) return -1;
    int floor= -1;
    Node* temp = root;
    while(temp!=NULL){
        if(temp->data == input) return input;
        if(temp->data > input){
            temp= temp->left;
        }else{
            floor= temp->data;
            temp= temp->right;
        }
    }
    return floor;
    
    }
};