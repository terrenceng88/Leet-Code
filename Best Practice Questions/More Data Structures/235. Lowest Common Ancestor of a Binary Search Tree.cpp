/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes 
p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a 
descendant of itself).”
*/



//Runs in O(V + E) time complexity using preorder reccursive traversal


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //because it's a binary search tree, we know that both p and q have to be on the same side of the current node or the current node is the lowest descendant
        if(root == NULL) {
            return NULL;
        }
        if( (p->val < root->val) && (q->val < root->val) ) {
            return lowestCommonAncestor (root->left, p, q); //left 
        } else if( (p->val > root->val) && (q->val > root->val) ) {
            return lowestCommonAncestor(root->right, p, q); //right 
        } else {
            return root;
        }
    }
};
