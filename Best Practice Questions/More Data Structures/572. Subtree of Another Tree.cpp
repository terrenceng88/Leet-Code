/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree 
of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of 
this node's descendants. The tree tree could also be considered as a subtree of itself.
*/



//Runs in O(n + m) time complexity using preorder reccursive traversal and serialization


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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { //O(n + m)
        //Serialization Method
        //Convert both trees into strings using preorder traversal O(n + m) (number of nodes in tree and subtree)
        //look for subtree in tree in string form O(n)

        string TreeRoot = serialize(root); //O(n)
        string SubRoot = serialize(subRoot); //O(m)

        //npos = no position
        return TreeRoot.find(SubRoot) != string::npos; //O(n)
    }

    //reccursive preorder traversal 
    string serialize(TreeNode* node) { //O(n)
        if(node == NULL) {
            return "null";
        }

        //need # to help find subtree later
        return "#" + to_string(node->val) + " " + serialize(node->left) + " " + serialize(node->right);
    }
};