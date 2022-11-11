/*
Given the root of a binary tree, invert the tree, and return its root.
*/


//Runs in O(V + E) using DFS

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) { //base case for recursive call
            return root;
        }
        
        TreeNode* temp = invertTree(root->left); //recursively call on left node
        root->left = invertTree(root->right); //recursively call on right node
        root->right = temp; //final switch between left and right nodes
        return root;
    }
};