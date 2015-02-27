#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(const ListNode *head)
{
    while (head) {
        cout << head->val << " ";
        head =  head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)
            return head;

        ListNode dummy_small(0);
        ListNode *small = &dummy_small;

        ListNode dummy_big(0);
        ListNode *big = &dummy_big;

        for (ListNode *cur=head; cur!=NULL; cur=cur->next) {
            if (cur->val < x) {
                small->next = cur;
                small = cur;
            } else {
                big->next = cur;
                big = cur;
            }
        }
        small->next = dummy_big.next;
        big->next = NULL;
        return dummy_small.next;
    }

    ListNode *partition_orig(ListNode *head, int x) {
        vector<int> less;
        vector<int> great;
        ListNode *p = head;
        while (p) {
            int val = p->val;
            if (val < x)
                less.push_back(val);
            else
                great.push_back(val);
            p = p->next;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *part = dummy;
        typedef vector<int>::const_iterator VIT;
        for (VIT it=less.begin(); it!=less.end(); ++it) {
            part->next = new ListNode(*it);
            part = part->next;
        }
        for (VIT it=great.begin(); it!=great.end(); ++it) {
            part->next = new ListNode(*it);
            part = part->next;
        }
        return dummy->next;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(2);
    print(head);

    int pivot = 3;
    ListNode *part = s.partition(head, pivot);
    print(part);

    return 0;
}
