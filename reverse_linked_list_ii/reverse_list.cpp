#include <iostream>
#include <stack>

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        for (int i=0; i<m-1; i++)
            pre = pre->next;

        ListNode *cur = pre->next;
        for (int j=0; j<n-m; ++j) {
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy.next;
    }

    ListNode *reverseBetween2(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fend = &dummy;
        for (int fstep=m-1; fstep>0; --fstep)
            fend = fend->next;

        ListNode *rhead = fend->next;
        ListNode *pre = NULL;
        ListNode *cur = rhead;
        int rstep = n-m+1;
        while (rstep-- > 0) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        rhead->next = cur;
        fend->next = pre;
        return dummy.next;
    }

    ListNode *reverseBetween_orig(ListNode *head, int m, int n) {
        if (m == n)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *preSub = dummy;
        for (int move=m-1; move>0; move--)
            preSub = preSub->next;

        ListNode *tailSub = preSub->next;
        ListNode *headSub = tailSub;
        ListNode *postSub = tailSub->next;
        int nstep = n - m;
        while (nstep-- > 0) {
            ListNode *third = postSub->next;
            postSub->next = tailSub;
            tailSub = postSub;
            postSub = third;
        }
        headSub->next = postSub;
        preSub->next = tailSub;
        return dummy->next;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    ListNode *head = new ListNode(10);
    ListNode *p = head;
    p->next = new ListNode(50);
    p = p->next;
    p->next = new ListNode(70);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(200);
    print(head);

    int m = 2;
    int n = 4;
    ListNode *rhead = s.reverseBetween(head, m, n);
    print(rhead);

    return 0;
}
