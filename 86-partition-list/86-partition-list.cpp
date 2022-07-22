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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        
        ListNode *l = left, *r = right;
        
        while(head){
            ListNode * &tmp = (head->val < x)? l: r;
            tmp->next = head;
            tmp = tmp->next;
            
            head = head->next;
        }
        
        l->next = right->next;
        r->next = NULL;
        
        return left->next;
        
    }
};