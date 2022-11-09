/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/


//Runs in O(n^2) time complexity (looked at answer)

class Solution {
public:
    /*
    string minWindow(string s, string t) {
        unordered_map<char, int> hashmap; //key = letter, value = how many times it shows up in t
        int left = 0; //pointer 1 for sliding window (goes first)
        int right = 0; //pointer 2 for sliding window (goes second)
        int head = 0; //head of the substring to be returned
        int size = INT_MAX; //size of the smallest substring so far
        int letters = t.size(); //number of letters in t that are found in s
        
        //fill hashmap with letters in t and how many times they show up
        for(int i = 0; i < t.size(); i++) { 
            hashmap[t[i]]++;
        }
        
        while(right < s.size()) { //iterate right pointer all the way to the end
            if(hashmap[s[right]] > 0) {
                letters--;
                hashmap[s[right]]--;
                right++;
                while(letters == 0) {
                    if(right - left < size)  {
                        size = right - left;
                        head = left;
                    }
                    if(hashmap[s[left]] == 0)  {
                        letters++;
                        hashmap[s[left]]++;
                        s[left]++;
                    }
                }
            }
        }
        
        if(size == INT_MAX) {
            return "";
        } else {
            return s.substr(head, size);
        }
    }
    */
    
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};
