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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        
        ListNode* p = head;
        ListNode* q = head->next;
        while (q != NULL) {
            if (p->val == q->val) {
                p->next = q->next;
            } else {
                p = p->next;
            }
            q = q->next;
        }
        
        return head;
    }
};
