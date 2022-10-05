/*
-----QUESTION-----
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

//Runs in O(n) time

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* PrevNode = NULL; //what's being set as the previous node
        ListNode* curr = head; //current node I'm on
        ListNode* NextNode = NULL; //the next node to move to in trversal (not in the reordered version)
        
        while(curr != NULL) {
            NextNode = curr->next;
            curr->next = PrevNode;
            PrevNode = curr;
            curr = NextNode;
        }
        
        return PrevNode;
    }
};