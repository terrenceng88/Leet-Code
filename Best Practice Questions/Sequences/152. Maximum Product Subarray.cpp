/*
-----QUESTION-----
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.
*/

//Runs in O(n) time 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int msf = nums[0]; //max so far is the first value in nums
        
        //we are multiplying with negatives so we need to have a min and max because the biggest produjct could be the smallest when multiplied with a negative
        int min_prod = 1; //minimum product acheived (negative)
        int max_prod = 1; // maximum product acheived (positive)
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) { //if current number in vector is negative
                swap(min_prod, max_prod); //switch the min and max products because the negative value flipped them
            }
            
            min_prod = min(min_prod * nums[i], nums[i]); //multiply value at i with current min product, compare with value at i and take the smallest
            max_prod = max(max_prod * nums[i], nums[i]); //multiply value at i with current max product, compare with value at i and take the largest
            
            msf = max(max_prod, msf); //set curr to new max so far is it is bigger
        }
        
        return msf; //return max so far 
    }
};