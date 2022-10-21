/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

//Runs in O(n) time complexity using 2 pointer method

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head; //1st pointer that moves normally
        ListNode* slow = head; //2nd pointer that moves at a delay of n behind the first pointer
        
        for(int i = 0; i < n; i++) { //fast pointer moves up n times first before slow pointer to create delay between fast and slow
            fast = fast->next;
        }
        
        if(fast == NULL) { //if fast is a nullptr after the for loop then that means the Nth node from the end is actually the first node
            return head->next;
        }
        
        while(fast->next != NULL) { //keep traversing until fast pointer reaches edge before NULL    
            fast = fast->next; //move the fast pointer up by 1
            slow = slow-> next; //move the slow pointer up by 1
        }
        
        slow->next = slow->next->next; //delete the Nth node from the end (slow pointer is just before it)
        
        return head;
    }
};