/*
-----QUESTION-----
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

//Runs in O(n) time using partial_sum and finding product of all values to the left and right of i

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result = nums; //vector to return
        vector<int> prefix = nums; //vector to hold prefix of i for multiplication
        vector<int> suffix = nums; //vector to hold suffix of i for multiplication
        
        int pre = 0; //prefix to be used for multiplication
        int suf = 0; //suffix to be used for multiplication
        
        //partial_sum(begin iterator, end iterator, result, operator (oprtional)); //performs operator on each index from begin to end at each index (addition if no operator)
        
        partial_sum(prefix.begin(), prefix.end(), prefix.begin(), multiplies<int>()); //calculates & stores prefix product at each index (front to back)
        partial_sum(suffix.rbegin(), suffix.rend(), suffix.rbegin(), multiplies<int>()); //calculates & stored suffix product at each index (back to front)
        
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) { //if current index if 0
                pre = 1;
            } else {
                pre = prefix[i - 1]; //get prefix value (product of everything before i) for multiplication
            }
            
            if(i + 1 < nums.size()) { //if current index is NOT last
                suf = suffix[i + 1]; //get suffix value (product of everything after i) for multiplication
            } else {
                suf = 1;
            }
            
            result[i] = pre * suf;
        }
        
        return result; 
    }
};