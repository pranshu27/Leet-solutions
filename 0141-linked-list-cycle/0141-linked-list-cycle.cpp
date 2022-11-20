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
        
        if(!head) return NULL;
        ListNode *slow, *fast;
        slow = head;
        fast = head->next;
        
        while(slow->next && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
            
        return false;
        
    }
};