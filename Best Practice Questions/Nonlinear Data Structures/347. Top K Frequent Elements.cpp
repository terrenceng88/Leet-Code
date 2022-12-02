/*
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.
*/

//Runs in O(nlogn) time complexity using map and pirority queue

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap; //key = number, value = how many times it appears
        vector<int> mostFrq; //vector of k most frequient elements
        
        for(int i = 0; i < nums.size(); i++) { //add numbers to hashmap with their frequency
                hashmap[nums[i]]++;
        }
        
        
        priority_queue<pair<int, int>> pq; //max priority queue by default (ordered by first element)
        for(auto [a, b] : hashmap) { //make pairs out of key and value in map (reversed) and add to priority queue (priority is the frequency)
            pq.push({b, a}); //priority queue insertion takes logn time
        }
        
        while(k > 0) { 
            mostFrq.push_back(pq.top().second); //add value to vector and remove from priority queue
            pq.pop();
            k--;
        }
        
        return mostFrq;
    }
};