/*
-----QUESTION-----
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
*/

//Runs in O(n) time using the sliding window technique

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msf = nums[0]; //msf = max so far
        int curr = 0; //current sum (max for each position I encounter)
        
        for(int i = 0; i < nums.size(); i++) { //go through entire array
            if(curr < 0) { //reset current value to 0 if negative because its not needed if it doesn't increase the sum for the max sub array
                curr = 0;
            }
            curr = curr + nums[i]; //add newest subarray index value to current sum
            msf = max(msf, curr); //set max so far to the greater of the two maxes so far (msf vs curr)
        }
        
        return msf;
    }
};