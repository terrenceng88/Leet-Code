/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path 
from the root node down to the farthest leaf node.
*/



//Runs in O(V+E) time using DFS


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) { //if both trees are null, they are the same so we will return true
            return true;
        }
        if(p == NULL || q == NULL) { //if one of them is null, then they cannot be equal so we will return false
            return false;
        }
        //when both nodes are not null, we first check if the values are equal
        //then recursively traverse the left and right subtree of both trees sequentially
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};