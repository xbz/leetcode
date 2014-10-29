#include <iostream>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

void print(ListNode *p) {
    while (p != NULL) {
        cout << p->val;
        p = p->next;
        if (p != NULL)
            cout << "->";
    }
    cout << endl;
}

void addNode(ListNode *p, int value) {
    if (p == NULL)
        return;

    ListNode *pCur = new ListNode(value);
    while (p != NULL) {
        if (p->next == NULL)
            break;
        p = p->next;
    }
    p->next = pCur;
}

// sumbit times(for the first accept): 1
int main(int argc, char *argv[])
{
    Solution s;
    ListNode *l1 = new ListNode(100);
    addNode(l1, 220);
    ListNode *l2 = new ListNode(100);
    addNode(l2, 150);
    addNode(l2, 200);
    addNode(l2, 250);
    addNode(l2, 300);
    ListNode *p = s.mergeTwoLists(l1, l2);
    print(p);

    return 0;
}
