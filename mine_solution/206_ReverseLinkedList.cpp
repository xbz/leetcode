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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = cur->next;
        
        while (true) {
            cur->next = pre;
            if (next == NULL) {
                break;
            }
            pre = cur;
            cur = next;
            next = next->next;
        }
        return cur;
    }
};
