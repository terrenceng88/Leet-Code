/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.
*/

//Runs in O(n) time complexity

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> tree;
    
    void inOrder(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        
        inOrder(root->left); //reccursive call on left child
        tree.push_back(root->val); //add to vector
        inOrder(root->right); //reccursive call on right child
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL) { //empty tree
            return true;
        }
        
        inOrder(root); //recursive call to add node values to vector
        
        for(int i = 1; i < tree.size(); i++) {
            if(tree[i] <= tree[i - 1]) {
                return false;
            }
        }
        
        return true; //if everything is right
    }
