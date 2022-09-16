/*
-----QUESTION-----
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

//Runs in O(n^2) time using 2 pointer technique

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; //vector of triples to be returned
        vector<int> triple; //vector to hold 1 triple
        int target; //sum of 2 values after the 3rd is fixed
        int front; //used for finding triplets (starts directly right of current index)
        int back; //used for finding triplets (starts at max index)
        
        //O(Log(n))
        sort(nums.begin(), nums.end()); //sort vector
        
        //O(n)
        for(int i = 0; i < nums.size(); i++) { //go through nums
            
            //kind of a sliding window technique starting after the current index of the sorted vector
            target = -nums[i]; //the result should be 0 when the second and third number are added to the first (a + b + c = 0, -a = b + c)
            front = i + 1; //index after current one
            back = nums.size() - 1; //last index 
            
            //O(n)
            while(front < back) { //loop through and try all combinations of sums of 2 numbers starting right of current index
                
                if(nums[front] + nums[back] < target) { //if sum of the 2 numbers is less than the target
                    front++; //move the front up one because lesser numbers wont increase it and you need to try other numbers
                    
                } else if (nums[front] + nums[back] > target) { //if sum of the 2 numbers is greater than the target
                    back--; //move the back down one because greater numbers wont decrease it and you need to try other numbers
                    
                } else { //the current number, front, and back added together get 0
                    triple = {nums[i], nums[front], nums[back]}; //make current number, front, and back into a triple
                    result.push_back(triple); //add triple to result
                        
                    //process duplicates of front
                    while(front < back and nums[front] == triple[1]) { //while the next number next to it is the same
                        front++; //skip over the duplicate (can do this because the vector is sorted)
                    }
                    
                    //process duplicates of back
                    while(front < back and nums[back] == triple[2]) { //while the next number next to it is the same
                        back--;  //skip over the duplicate (can do this because the vector is sorted)
                    }
                }
            }
            
            //O(n)
            while(i + 1 < nums.size() and nums[i + 1] == nums[i]) { //process duplicates of the current number
                i++;
            }
        }
        
        
        return result;
    }
};