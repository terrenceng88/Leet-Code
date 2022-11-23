/*
Given two integer arrays preorder and inorder where preorder is 
the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.
*/

//Runs in O(

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
        Pre-order Traversal
        - visit the root first
        - traverse left subtree
        - traverse right subtree
        
        In-order Traversal
        - traerse left subtree
        - visit root
        - traverse right subtree
        */

        
    }
};