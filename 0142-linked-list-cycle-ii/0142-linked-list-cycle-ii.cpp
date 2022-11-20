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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while(slow->next && fast->next && fast->next->next)
        {   
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
               slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        
        return NULL;
        // return slow;
        
        
    }
};