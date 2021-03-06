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
        cout << head->val;
        head =  head->next;
        if (head)
            cout << "->";
    }
    cout << endl;
}

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head)
            return head;

        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *p = head;
        while (p) {
            p = p->next;
            if (n > 0) {
                n--;
                continue;
            }

            pre = cur;
            cur = cur->next;
        }

        if (!pre)
            return head->next;

        pre->next = cur->next;
        return head;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    ListNode *head = new ListNode(10);
    // ListNode *p = head;
    // p->next = new ListNode(50);
    // p = p->next;
    // ListNode *q = p;
    // p->next = new ListNode(70);
    // p = p->next;
    // p->next = new ListNode(200);
    // p = p->next;
    // p->next = q;
    print(head);

    int n = 3;
    if (argc == 2)
        n = atoi(argv[1]);
    ListNode *newhead = s.removeNthFromEnd(head, n);
    print(newhead);

    return 0;
}
