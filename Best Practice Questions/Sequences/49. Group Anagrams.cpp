/*
-----QUESTION-----
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/

//Runs in O(n) + O(n) = O(2n) = O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result; //resul;t to be returned
        unordered_map<string, vector<string>> map; //hashmap to hold words for anagrams (sorted string is the key, original string is the value)
        
        //O(n)
        for(int i = 0; i < strs.size(); i++) {
            string word = strs[i]; //get string at index i of strs (leave unsorted)
            sort(strs[i].begin(), strs[i].end()); //sort the string
            map[strs[i]].push_back(word); //add unsorted string to value in the map at the key, sorted string is the key and the original string becomes the value
        }
        
        //O(n)
        for(auto i = map.begin(); i != map.end(); i++) { //traverse through the map
            result.push_back(i -> second); //add the grouped strings to the result vector (value of the key in the map, that's why "i -> second" is used)
        }
        
        return result;
    }
};