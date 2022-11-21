/*
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals 
non-overlapping.
*/

//Runs in O(nlogn + n) = O(nlogn) time complexity using 2 pointers

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int removals = 0; //number of removals to make so that intervals don't interlap
        int prev = 0; //previous interval
        
        //O(nlogn)
        sort(intervals.begin(), intervals.end()); //sort the vector of intervals in order (based on beginning number of each interval)
        
        //O(n)
        for(int i = 1; i < intervals.size(); i++) { //iterate through the intervals
            if(intervals[i][0] < intervals[prev][1]) { //overlapping interval is found when the previous interval's ending number is greater than the current interval's beginning number
                removals++; //another interval to be removed
                if(intervals[i][1] < intervals[prev][1]) { //if the ending number of the current interval is less than the ending number of the previous interval
                    prev = i;  //set previous interval to current interval
                }
            } else { //only move on to next interval if not overlapped
                prev = i; //set previous interval to current interval
            }
        }
        
        return removals; 
    }
};



