/*----------------------- Question -----------------------*/
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

/*----------------------- Solution -----------------------*/
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
    
    //spits and explores postorder and inorder recursively
    TreeNode* splitter(vector<int>::iterator inFront, vector<int>::iterator inBack, 
                       vector<int>::iterator postFront, vector<int>::iterator postBack) {
        
        if(inFront == inBack && postFront == postBack) {
            return NULL; //return null if done
        }
        
        //root is last index of postorder vector
        int rootVal = *(postBack - 1); //last char is a null terminator
        TreeNode* root = new TreeNode(rootVal); 
        
        //finds where the root is in the inorder traversal
        auto inRoot = find(inFront, inBack, rootVal);
        
        //finds where the split point in the postorder traversal is
        auto postSplit = postFront + static_cast<int>(inRoot - inFront);
        
        root->left = splitter(inFront, inRoot, postFront, postSplit);
        root->right = splitter(inRoot + 1, inBack, postSplit, postBack - 1);
        
        return root;        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //last char is a null terminator
        return splitter(inorder.begin(), inorder.end(), postorder.begin(), postorder.end()); 
    }
};