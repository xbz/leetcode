#include <iostream>
#include <set>

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
}

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;

        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != slow) {
            if (fast==NULL || fast->next==NULL)
                return false;

            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }

    bool hasCycle_orig(ListNode *head) {
        if (!head)
            return false;
        set<ListNode *> s;
        ListNode *p = head;
        while (p) {
            if (s.find(p) != s.end())
                return true;
            s.insert(p);
            p = p->next;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    ListNode *head = new ListNode(10);
    ListNode *p = head;
    p->next = new ListNode(50);
    p = p->next;
    ListNode *q = p;
    p->next = new ListNode(70);
    p = p->next;
    p->next = q;
    // print(head);

    bool bCycle = s.hasCycle(head);
    cout << "has cycle:" << bCycle << endl;

    return 0;
}
