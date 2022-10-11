/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/

//Runs in O(log n) time complexity and uses O(n) space using Binary Search (Binary search runs in O(log n) time)

/*
In this problem, we have only three cases.

Case 1. The leftmost value is less than the rightmost value in the list: 
This means that the list is not rotated.
e.g> [1 2 3 4 5 6 7 ]

Case 2. The value in the middle of the list is greater than the leftmost and rightmost values in the list.
e.g> [ 4 5 6 7 0 1 2 3 ]

Case 3. The value in the middle of the list is less than the leftmost and rightmost values in the list.
e.g> [ 5 6 7 0 1 2 3 4 ]

As you see in the examples above, if we have case 1, we just return the leftmost value in the list. 
If we have case 2, we just move to the right side of the list. 
If we have case 3 we need to move to the left side of the list.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0; //starts at first index
        int right = nums.size() - 1; //starts at last index of nums
        
        while(left < right) {
            int mid = left + (right - left)/2; //calculate the midpoint
            
            if(nums[left] < nums[right]) { //if value at the left point is less than the value at the right point
                return nums[left]; //smallest value has been found at left point, return it
            }
                
            
            if(nums[left] <= nums[mid]) { //if value at left point is less than value at mid 
               left = mid + 1; //move to the right side
            } else { 
                right = mid; //move to the left side
            }
        }
        
        return nums[left]; //smallest value is at the left most point, return it
    }
};