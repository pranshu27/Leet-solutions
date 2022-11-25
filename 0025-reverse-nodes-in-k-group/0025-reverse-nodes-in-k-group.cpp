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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head) return NULL;
        
        ListNode *curr = head, *prev = NULL;
        int ctr = 0;

        int l = 0;
        ListNode *t = head;
        while(t && l<k){
            t=t->next;
            l++;
        }
        if(l == k){
            while(ctr<k&&curr){
                ctr++;
                ListNode *tmp = curr->next;
                curr->next = prev; 
                prev = curr;
                curr = tmp;
                // ctr++;
            }
        
            if(ctr<k) prev = head; 

            head->next = reverseKGroup(curr, k);
            return prev;
        }
        return head;
            
    }
};