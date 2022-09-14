
/*
-----QUESTION-----
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap; //hash map to hold numbers seen so far in vector (key = number, value = index of that number in the vector)
        vector<int> answer; //vector to be returned
        int NumToFind; //number to look for in the hashmap
        
        for(int i = 0; i < nums.size(); i++) { //go through vector
            NumToFind = target - nums[i]; //compute the number you need to find in the hashmap
            
            if(hashmap.find(NumToFind) != hashmap.end()) { //if the number you are looking are is in the hashmap
                answer.push_back(hashmap[NumToFind]); //get index for number in hashmap and add to answer vector
                answer.push_back(i); //get current index and add to answer vector
                return answer; //return the answer
            }
                                 
            hashmap[nums[i]] = i; //add number to hashmap if it was not already in it
        }
        
        return answer;
    }
};
