#include <iostream>
#include <unordered_set>
#include <algorithm>

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
        unordered_set<ListNode *> ha = build(headA);

        ListNode *pb = headB;
        while (pb) {
            if (find(ha.begin(), ha.end(), pb) != ha.end())
                return pb;
            pb = pb->next;
        }
        return NULL;
    }

private:
    unordered_set<ListNode *> build(ListNode *head) {
        unordered_set<ListNode *> ret;
        ListNode *p = head;
        while (p) {
            ret.insert(p);
            p = p->next;
        }
        return ret;
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
    pb->next = heada->next->next;
    // p->next = q;
    print(headb);

    ListNode *inter = s.getIntersectionNode(heada, headb);
    if (!inter)
        cout << "inter is NULL" << endl;
    else
        cout << "inter:" << inter->val << endl;

    return 0;
}
