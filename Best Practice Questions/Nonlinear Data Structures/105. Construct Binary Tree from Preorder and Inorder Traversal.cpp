/*
Given two integer arrays preorder and inorder where preorder is 
the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.
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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    //reccursive helper function to build the tree
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int pivot = left;  // find the root from inorder
        while(inorder[pivot] != preorder[rootIdx]) { //keep moving the pivot until it reaches the root index
            pivot++;
        }
        
        rootIdx++; 
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, left, pivot-1); //recursively call on the left side
        newNode->right = build(preorder, inorder, rootIdx, pivot+1, right); //recursively call on the right side
        return newNode;
    }
};