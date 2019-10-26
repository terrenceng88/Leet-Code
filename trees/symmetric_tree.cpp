/*----------------------- Question -----------------------*/
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.
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

    bool symFind (TreeNode* l, TreeNode* r) {
        if (!l && !r ){ //checks if same value for both (even NULL's)
            return true;
        }
        else if (!l || !r){ //checks if one is null and one isnt
            return false;
        }
        else if (l->val != r->val){ //checks if both nodes have same value
            return false;
        }
        return symFind(l->left, r->right) && symFind(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true; //edge case
        }
        return symFind(root-> left, root->right);
    }
};