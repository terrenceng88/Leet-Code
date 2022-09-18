/*
-----QUESTION-----
Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.
*/

//Runs in O(nLogn) + O(n) = O(nLogn) time

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) { //return intervals if only 1 in it because it can't overlap if only 1
            return intervals;
        }
        
        vector<vector<int>> result; //vector of intervals to be returned
        
        //O(nLogn)
        sort(intervals.begin(), intervals.end()); //sort the vector of intervals in order (based on beginning number of each interval)
        
        result.push_back(intervals[0]); //push the first interval into the result
        
        //O(n)
        for(int i = 1; i < intervals.size(); i++) { //traverse through intervals (start at index 1 because already put index 0 in the result)
            if(result.back()[1] >= intervals[i][0]) { //if overlaps (the ending point of the last pair in result is less than the starting point of current interval)
                result.back()[1] = max(result.back()[1], intervals[i][1]); //merge the interval (ending point of last pair is set to the ending point of current interval if it is higher than it currently is)
            } else {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};

