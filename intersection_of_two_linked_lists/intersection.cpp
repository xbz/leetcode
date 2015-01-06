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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = len(headA);
        int lenb = len(headB);

        int diff = abs(lena - lenb);
        while (diff > 0) {
            if (lena > lenb)
                headA = headA->next;
            else
                headB = headB->next;
            diff--;
        }

        while (headA && headB) {
            if (headA == headB)
                return headA;

            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }

private:
    int len(ListNode *head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        return n;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    ListNode *heada = new ListNode(10);
    ListNode *p = heada;
    p->next = new ListNode(50);
    p = p->next;
    // ListNode *q = p;
    p->next = new ListNode(70);
    p = p->next;
    p->next = new ListNode(200);
    p = p->next;
    // p->next = q;
    print(heada);

    ListNode *headb = new ListNode(3);
    ListNode *pb = headb;
    pb->next = new ListNode(5);
    pb = pb->next;
    pb->next = heada;
    // p->next = q;
    print(headb);

    ListNode *inter = s.getIntersectionNode(heada, headb);
    if (!inter)
        cout << "inter is NULL" << endl;
    else
        cout << "inter:" << inter->val << endl;

    return 0;
}
