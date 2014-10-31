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
        ListNode *ret = new ListNode(0);
        ListNode *p = ret;
        while (l1!=NULL || l2!=NULL) {
            // 1. l1==NULL && l2!=NULL
            //    use l2
            // 2. l1!=NULL && l2==NULL
            //    use l1
            // 3. l1!=NULL && l2!=NULL
            //    use l1 if l1->val< l2->val
            //    use l2 if l1->val>=l2->val
            if (l2==NULL || (l1!=NULL && l1->val<l2->val)) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            };
            p = p->next;
        }

        return ret->next;
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
    ListNode *l1 = new ListNode(180);
    addNode(l1, 280);
    ListNode *l2 = new ListNode(100);
    addNode(l2, 150);
    addNode(l2, 200);
    addNode(l2, 250);
    addNode(l2, 300);
    ListNode *p = s.mergeTwoLists(l1, l2);
    print(p);

    return 0;
}
