
/*
-----QUESTION-----
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.
*/

//Runs in O(n) time using Map

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> seen; //map to hold all numbers seen
        
        for(int i = 0; i < nums.size(); i++) {
            if(seen.find(nums[i]) != seen.end()) { //if number has already been seen
                return true;
            } else { //hasn't been seen yer
                seen[nums[i]] = 1; //add numbner to map
            }
        }
        
        return false;
    }
};