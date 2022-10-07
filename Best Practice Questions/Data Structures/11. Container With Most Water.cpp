/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

//Runs in O(n) time using O(1) space using 2 pointer method

/*
//Runs in O(nlogn) time (too slow and exceeds time limit)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; //pointer to start at beginning of height vector
        int right = height.size() - 1; //pointer to start at end of height vector
        
        int curr = 0; //current volume
        int maxVol = 0; //max volume so far
        
        while(left < right) {
            int temp = left;
            while(temp < right) {
                curr = (right - temp) * min(height[temp], height[right]);
                maxVol = max(curr, maxVol);
                temp++;
            }
            right--;
        }
        
        return maxVol;
    }
};
*/

/*
//Runs in O(n) time using O(1) space using 2 pointer method
//Start by getting the volume of the widest container (both ends), all other possible containers are less wide, so in order to hold more water, they need to be higher
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; //pointer to start at beginning of height vector
        int right = height.size() - 1; //pointer to start at end of height vector
        
        int curr = 0; //current volume
        int maxVol = 0; //max volume so far
        
        while(left < right) {
            curr = (right - left) * min(height[left], height[right]); //calculate current volume
            maxVol = max(curr, maxVol); //set new max volume if current is bigger
            
            //move the lower height closer because doing so does not eliminate the final answer (only need to multiply by larger heights to find max volume because width is shrinking)
            if(height[left] < height[right]) { 
                left++;
            } else {
                right--;
            }
        }
        
        return maxVol;
    }
};
*/


//faster version of 2nd attempt by skipping over multiple lower heights at a time instead of just 1
//Runs in O(n) time using O(1) space using 2 pointer method
//Start by getting the volume of the widest container (both ends), all other possible containers are less wide, so in order to hold more water, they need to be higher
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; //pointer to start at beginning of height vector
        int right = height.size() - 1; //pointer to start at end of height vector
        
        int minheight = 0; //smaller of the two heights (left or right)
        int curr = 0; //current volume
        int maxVol = 0; //max volume so far
        
        while(left < right) {
            minheight = min(height[left], height[right]);
            curr = (right - left) * minheight; //calculate current volume
            maxVol = max(curr, maxVol); //set new max volume if current is bigger
            
            //move the lower height closer because doing so does not eliminate the final answer (only need to multiply by larger heights to find max volume because width is shrinking)
            while(height[left] <= minheight && left < right) { 
                left++;
            }
            while(height[right] <= minheight && left < right) {
                right--;
            }
        }
        
        return maxVol;
    }
};
