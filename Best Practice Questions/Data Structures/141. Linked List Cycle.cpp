/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/

//Runs in O(n) time and O(1) space using 2 pointer fast & slow method

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
//runs in O(n) time and O(n) space using a hashmap and the head pointer
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
*/

//runs in O(n) time and O(1) space using 2 pointer (fast & slow method)
//works in the same way as 2 runners (1 fast and 1 slow) in a track, there will always be a point when the 2 meet and when that happens you know the track is circular
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) {  //edge case for if empty linkedlist 
            return false;    
        }
        
        ListNode* slow = head; //slow moving node starts at head (when fast and slow meet up again, we know its a cycle)
        ListNode* fast = head; //fast moving node starts at head (when fast and slow meet up again, we know its a cycle)
        
        while(fast->next && fast->next->next) { //as long as end of linked list has not been reached (2 nodes exist after fast)
            slow = slow->next; //move the slow node up by 1
            fast = fast->next->next; //move the fast node up by 2
            
            if(slow == fast) { //if fast and slow node meet up then we know there is a cycle
                return true;
            }             
        }
        
        return false;
    }
};