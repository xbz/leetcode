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
    void reorderList(ListNode *head) {
        stack<ListNode *> s;
        ListNode *p = head;
        while (p) {
            s.push(p);
            p = p->next;
        }
        cout << s.size() << endl;
        int len = s.size();
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pCur = head;
        int limit = len / 2;
        for (int i=0; i<limit; ++i) {
            ListNode *next = pCur->next;
            ListNode *pRcur = s.top();
            s.pop();
            if (i%2==1 && i==limit-1)
                pCur->next = NULL;
            else
                pCur->next = pRcur;
            if (i == limit-1)
                pRcur->next = NULL;
            else
                pRcur->next = next;
        }
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

    s.reorderList(head);
    print(head);

    return 0;
}
