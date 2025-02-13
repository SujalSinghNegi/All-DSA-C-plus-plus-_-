// inorder + (post or pre) => construct BT

/* inorder = [40,20,50,10,60,30]   left root right
    preorder = [10,20,40,50,30,60]  root left right

    root 10, left = [40,20,50], right = [60,30]
                     
                      10
             
              /              \
            40 20 50        60 30

    root 20, left = [40], right = [50]
                   20
              /          \
            40             50

    root 30, left = [60], right = []
                   30
              /          \
            60             NULL

                         10
                      /     \
                     /       \
                    /         \
                   /           \
                  20           30
                /    \       /    \
               40     50    60     NULL



*/

#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
 inorder  [9,3,15,20,7]
           0 1 2  3  4
 preorder [3,9,20,15,7]


 preorder= [1,2,4,8,9,5,10,11,3,6,12,7]
 inorder = [8,4,9,2,10,5,11,1,12,6,3,7]
 
                       1
                   /      \
                  /        \    
                 /          \
                /            \
                2             3
             /    \          /  \
            4      5        6    7
           /  \   /  \     / 
          8    9 10  11   12



*/



class Solution {
public:
    Node* buildTree(vector<int>& preorder, int Pstart, int Pend, vector<int>& inorder, int Istart, int Iend, map<int, int>& mpp) {
        if (Pstart > Pend || Istart > Iend) return nullptr;

        // Create the root node with the current value in preorder
        Node* root = new Node(preorder[Pstart]);

        // Find the index of the root value in the inorder traversal
        int index = mpp[root->data];

        // Calculate the number of nodes in the left subtree
        int numsleft = index - Istart;

        // Recursively construct the left and right subtrees
        root->left = buildTree(preorder, Pstart + 1, Pstart + numsleft, inorder, Istart, index - 1, mpp);
        root->right = buildTree(preorder, Pstart + numsleft + 1, Pend, inorder, index + 1, Iend, mpp);

        return root;
    }

    Node* build(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;

        // Map each value to its index in the inorder traversal for quick access
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }

        // Call the recursive function to construct the tree
        return buildTree(preorder, 0, n - 1, inorder, 0, n - 1, mpp);
    }
};
