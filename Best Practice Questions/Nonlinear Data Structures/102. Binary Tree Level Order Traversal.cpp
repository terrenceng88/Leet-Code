/*
Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).
*/



//Runs in O(n) time complexity using BFS


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //need BFS for this
        vector<vector<int>> answer; //vector of vectors to hold each level of tree nodes from left to right 
        if(!root) return answer; //if tree empty, return
        queue<TreeNode*> q; //queue to 
        q.push(root); //queue to hold current level of tree

        while(!q.empty()) { //continue until every level of the tree is explored
            int size = q.size();
            vector<int> vec; //create vector to hold nodes for this level
            while(size--) { //check every node for this level
                TreeNode* f = q.front(); //move through nodes from left to right
                vec.push_back(q.front()->val);
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            answer.push_back(vec); //add vetor of nodes for this level to answer
        }
        return answer;
    }
};