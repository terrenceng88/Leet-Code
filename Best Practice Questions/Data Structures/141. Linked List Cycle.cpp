/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/

//Runs in O(n) time

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) {  //edge case for if empty linkedlist 
            return false;    
        }
        
        if(head->next == NULL) { //edge case for if only 1 node in linkedlist 
            return false;
        }
        
        unordered_map<ListNode*, int> hashmap; //key = current node, value = val at current node 
        
        while(head != NULL) {
            if(hashmap.find(head) != hashmap.end()) { //if current node is in hashmap (cycle)
                return true;
            } else { //if current node is not in the hashmap
                hashmap[head] = head->val; //add to hashmap
                head = head->next; //move to next node in linked list
            }
        }
        
        return false;
    }
};