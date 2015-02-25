#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return head;

        // one poniter solution
        ListNode *cur = head;
        while (cur->next != NULL) {
            if (cur->val == cur->next->val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else
                cur = cur->next;
        }

        return head;
    }

    ListNode *deleteDuplicates_orig(ListNode *head) {
        if (head==NULL || head->next==NULL)
            return head;

        ListNode *newlast = head;
        ListNode *p = head->next;
        while (p != NULL)
            if (p->val != newlast->val) {
                newlast->next = p;
                newlast = newlast->next;
                p = p->next;
            } else {
                ListNode *tmp = p;
                p = p->next;
                delete tmp;
            }

        newlast->next = NULL;
        return head;
    }

    ListNode *deleteDuplicates_val(ListNode *head) {
        if (head==NULL || head->next==NULL)
            return head;

        ListNode *newlast = head;
        ListNode *cur = head->next;
        while (cur != NULL) {
            if (cur->val != newlast->val) {
                newlast = newlast->next;
                newlast->val = cur->val;
            }
            cur = cur->next;
        }

        cur = newlast->next;
        while (cur != NULL) {
            ListNode *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        newlast->next = NULL;

        return head;
    }
};

void print_list(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(2);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(6);
    p->next->next->next->next->next = new ListNode(6);
    p->next->next->next->next->next->next = new ListNode(8);

    print_list(p);
    Solution sol;
    ListNode *new_list = sol.deleteDuplicates(p);
    print_list(new_list);

    return 0;
}
