/*----------------------- Question -----------------------*/
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        vector<int> level; //vector for each level of tree
        queue<TreeNode*> stack; //queue for going level by level
        
        if(root == NULL) {
            return result;
        }
        
        stack.push(root); //pushes root to queue
        stack.push(NULL); //uses NULL to indicate level change
        
        while(stack.size() != 0) {
            
            TreeNode * current = stack.front();
            stack.pop();
            
            if(current == NULL) { //checks if different level
                result.push_back(level);
                level.clear(); 
                if(stack.size() > 0) {
                    stack.push(NULL); //uses null to seperate level
                }
                
            }
            else 
            {
                level.push_back(current->val);
                if(current->left != NULL) {
                    stack.push(current->left);
                }
                if(current->right != NULL) {
                    stack.push(current->right);
                }  
            }
        }
        return result;
    }
};