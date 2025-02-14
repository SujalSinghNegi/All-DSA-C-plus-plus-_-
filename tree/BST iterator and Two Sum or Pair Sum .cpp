// here implementing the how to put a iterator in a BST
// like in the array we put pointer in the first index or at the last index
// similarly on the Inorder traversal of BST , if I put a iterator on the leftest index and then move the inorder then it will give the 
// elements in the ascending order , as i requested, not all elements in one time, 
// and if i put the iterator on the rightest, or say i reverse the procedure, i get the descending elements , in the reverse inorder

// make a Class for BST iterator , and have the function which will show the next element, and check hasNext, and with that a bool value, if false means in ascending order, and if true then in descending order

// for making two sum problem , 

class TwoSum{
    public:
    bool findTarget(Node* root, int k){ // k is the required target
    if(root==NULL) return false;
    // false, which means the ascending order elements
    // true, which means the descending order elements
    BstIterator l = new BstIterator(root, false); 
    BstIterator r = new BstIterator(root, true); 
   // BstIterator l(root, false); 
   // BstIterator r(root, true); 
    
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
class BstIterator{
    stack<Node*>st;
    public:
    BstIterator(Node* root, bool reverse){

    }
    bool hasNext(){

    }
    int next(){

    }


};
