/*
You are given a string s and an integer k. 
You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/

//Runs in O(n) time

class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(); //size of string s
        int currmax = 0; //holds current max length of longest repeating substring with character replacement
        vector<int> count(26, 0); //vector of size 26, filled with 0's
        int start = 0; //start of sliding window
        int end = 0; //end of sliding window
        int globalMaxFreq = 0; 
        
        for(; end<size; end++){ //iterate through string s with end of sliding window first
            count[s[end]-'A'] += 1; //increase count for specific letter in count vector (- 'A') gets the exact number of letter it is (1-26 in alphabet)
            globalMaxFreq = max(globalMaxFreq, count[s[end]-'A']); //get length of longest repeating character so far
            if((end-start+1)-globalMaxFreq > k) { //if longest repeating character uses more than k replacements
                currmax = max(currmax, (end-start)); //reestablish longest repeating character
                count[s[start]-'A'] -= 1; //delete 1 from the letter in count vector
                start += 1; //move start of sliding window up by 1
            }
        }
        
        return max(currmax, end-start); //return longest length
    }
};