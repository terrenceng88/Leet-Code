/*
-----QUESTION-----
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/

//Runs in O(n) time 

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<char, int> letters; //map to hold all letters seen so far in string s
        
        if(s.length() != t.length()) { //check if same length
            return false;
        }
        
        for(int i = 0; i < s.size(); i++){ //go through string s
            letters[s[i]]++; //add letter with occurence value to map
        }
        
        for(int i = 0; i < t.size(); i++) { //go through string t
            if(letters[t[i]] == 0) { //if t contains a letter not in s or too many of a letter contained
                return false;
            } else {
                letters[t[i]]--; //decrement letter occurence in map
            }
        }
        
        return true;
        
        
        /*
        int a[26] = {};
        for (unsigned char c: s) {
            a[c - 'a']++;
        }
        for (unsigned char c: t) {
            if (--a[c - 'a'] < 0) return false;
        }
        return s.size() == t.size();
        */
    }

    
};