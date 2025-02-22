// here implementing the how to put a iterator in a BST
// make a Class for BST iterator , and have the function which will show the next element, and check hasNext, and with that a bool value, if false means in ascending order, and if true then in descending order
// like in the array we put pointer in the first index or at the last index
// similarly on the Inorder traversal of BST , if I put a iterator on the leftest index and then move the inorder then it will give the 
// elements in the ascending order , as i requested, not all elements in one time, 
// and if i put the iterator on the rightest, or say i reverse the procedure, i get the descending elements , in the reverse inorder

class BstIterator{
    private:
    stack<Node*>st;
    bool reverse = false;
     private:
     // pushAll will push all the elements in the left or right accordingly to the reversed or not reversed
    void pushAll(Node* root){
        while(root!= NULL){
            st.push(root);
            if(!reverse) root = root->left; // ascending
            else root= root->right;  // descending
        }
        
    }
    public:
    BstIterator(Node* root, bool reverse){
        this->reverse= reverse;
        pushAll(root);
    }
    BstIterator(Node* root){
        pushAll(root); // By default the iterator gives element in ascending order
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        Node* node = st.top();
        st.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->data;
    }
   

};


// for making two sum problem , 
// if make the left pointer to the leftest and right pointer to the rightest as smallest and largest number on the bst
// if there sum is small then move the left pointer to the right for big number and 
// if the sum is large then move the right pointer to the left, for small sum
// when the left and right pointer come to same it means they didnt found any pair that sum to target



class Solution{
    public:
    bool findTarget(Node* root, int target){
        int k= target; // k is the required target
    if(root==NULL) return false;
    // false, which means the ascending order elements
    // true, which means the descending order elements
    BstIterator l(root, false); 
    BstIterator r(root, true); 
    
    int i = l.next();
    int j= r.next();
   // then make two sum
   while(i<j){
    if(i+j==k) return true;
    else if(i+j < k) i = l.next(); // moving the left pointer to the right , 
    else j= r.next();  // moving the right pointer to the left
   }
   return false;
    }
};