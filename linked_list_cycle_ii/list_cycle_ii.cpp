#include <iostream>
#include <unordered_set>

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
	ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
				while (slow != head) {
					slow = slow->next;
					head = head->next;
				}
				return slow;
            }
        }
        return NULL;
    }

	ListNode *detectCycle_2(ListNode *head) {
        bool cycle = false;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                cycle = true;
                break;
            }
        }
        if (!cycle)
            return NULL;
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }

	ListNode *detectCycle_extra_space(ListNode *head) {
        unordered_set<ListNode *> s;
        while (head != NULL) {
            if (s.count(head) > 0)
                return head;
            s.insert(head);
            head = head->next;
        }
        return NULL;
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

    ListNode *start = s.detectCycle(head);
    cout << "cycle start:" << start << endl;

    return 0;
}
