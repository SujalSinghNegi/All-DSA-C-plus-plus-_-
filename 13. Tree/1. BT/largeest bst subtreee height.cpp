// height of largest bst subtree possible
class Solution {
private:
    NodeValue largestBSTSubtreeHelper(Node* root) {
        // Base case: An empty tree is a BST of size 0
        if (!root) 
            return NodeValue(INT_MAX, INT_MIN, 0);

        // Get values from left and right subtrees
        NodeValue left = largestBSTSubtreeHelper(root->left);
        NodeValue right = largestBSTSubtreeHelper(root->right);

        // If the current node is greater than max in left AND smaller than min in right, it is a BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(
                min(root->data, left.minNode), 
                max(root->data, right.maxNode), 
                left.maxSize + right.maxSize + 1
            );
        }

        // Otherwise, return an invalid range to indicate it's not a BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBst(Node* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};