/*
-----QUESTION-----
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot 
index k (1 <= k < nums.length) such that the resulting array is 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, 
return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

//Runs in O(log n) time using Binary Search (Binary search runs in O(log n) time)


/*
---------- PSEUDO CODE ----------
1. Find middle point mid = (l + h)/2
2. If key is present at middle point, return mid.
3. Else If arr[l..mid] is sorted
	a) If key to be searched lies in range from arr[l]
	   to arr[mid], recur for arr[l..mid].
	b) Else recur for arr[mid+1..h]
4. Else (arr[mid+1..h] must be sorted)
	a) If key to be searched lies in range from arr[mid+1]
	   to arr[h], recur for arr[mid+1..h].
	b) Else recur for arr[l..mid]

PS: The psuedocode is taken from geeksforgeeks 
*/

/*
just for myself to better understand the problem and pseudo code
	1  2  3  4  5  6  7
	2  4  5  6  7  1  3
	6  7  1  2  3  4  5
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0; //starts at first index of nums
        int high = nums.size() - 1; //starts at last index of nums
        int mid; //mid point
        
        while(low <= high) { //loop until target is found in nums (low = high for worst case)
            mid = low + (high - low)/2; //calculate the midpoint
            if(nums[mid] == target) { //if mid is the index of the target
                return mid; //return it (the answer)
            } 
            
            if(nums[low] <= nums[mid]) { //if left half is the sorted one
                if(nums[low] <= target and target <= nums[mid]) { //if target is in the left half
                    high = mid - 1; //move high point in closer to find target
                } else { //if target is in the right half
                    low = mid + 1; //move low point in closer to find target
                }
            } else { //if the right half is the sorted one
                if(nums[mid] <= target and target <= nums[high]) { //if target isin the right half
                    low = mid + 1; //move low point in closer to find target
                } else { //if target is in the left half
                    high = mid - 1; //move high point in closer to find target
                } 
            }
        }
        
        return -1; //return -1 if target is not in nums
    }
};



