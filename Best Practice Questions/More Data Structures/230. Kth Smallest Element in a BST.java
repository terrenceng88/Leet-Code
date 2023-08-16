/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/


//runs in O(n) time complexity using recursive InOrder Traversal (beats 100% of users in Java with Memory)



/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private static int counter; //global var for counter to find k smallest
    private static int ksmall; //to be returned in the end (kth smallest value)
   
    public int kthSmallest(TreeNode root, int k) {
        counter = k;
        inorder(root);
        return ksmall;
    }


    void inorder(TreeNode root) {
        if(root.left != null) {
            inorder(root.left);
        }


        counter--; //start counting once smallest val is found
        if(counter == 0) { //base case (when reaches kth smallest value)
            ksmall = root.val;
        }


        if(root.right != null) {
            inorder(root.right);
        }


        return;
    }


    /* pseudo code - need to use inorder (left, middle, right)
         counter = k


        recurrsive (root) {
            reccursive call left


            if(counter == k) {
                return value at current node
            }


            reccursive call right


            counter--
        }
        */
}
