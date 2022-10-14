/*
Given a string s, find the length of the longest substring without repeating characters.
*/

//Runs in O(n) time complexity

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashmap; //map to hold 
        int start = -1; //index to start the longest substring without repeating characters at (-1 so that the "i - start" math matches up later to include the current letter)
        int longest = 0; //length of longest substring without repeating characters
        
        for(int i = 0; i < s.size(); i++) { //iterate through string s
            if(hashmap.find(s[i]) != hashmap.end() and hashmap[s[i]] > start) { //if current letter has been seen before and it's last index was after the current starting point
                start = hashmap[s[i]]; //set index as the starting point for finding longest substring without repeating characters
            }
            hashmap[s[i]] = i;  //add current letter to hashmpa with letter as key and index as value
            longest = max(longest, i - start); //set new longest if current substring length is longer than longest so far
        }
        
        return longest; //return longest substring without repeating characters
    }
};