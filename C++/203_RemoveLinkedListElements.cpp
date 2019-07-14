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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* notEqual = &dummy;
        
        while (notEqual->next != NULL) {
            if (notEqual->next->val == val) {
                notEqual->next = notEqual->next->next;
            } else {
                notEqual = notEqual->next;
            }
        }
        return dummy.next;
    }
};
