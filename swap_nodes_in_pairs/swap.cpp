#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head==NULL || head->next==NULL)
            return head;

        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *new_head = head->next;
        while (cur != NULL) {
            ListNode *next = cur->next;
            if (next == NULL)
                break;

            cur->next = next->next;
            next->next = cur;
            if (pre != NULL)
                pre->next = next;

            pre = cur;
            cur = cur->next;
        }
        return new_head;
    }

    // add dummy node
    ListNode *swapPairs_dummy(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while (cur!=NULL && cur->next!=NULL) {
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;

            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }

    // add dummy node(better version)
    ListNode *swapPairs_dummy2(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur->next!=NULL && cur->next->next!=NULL) {
            cur->next = swap(cur->next, cur->next->next);
            cur = cur->next->next;
        }
        return dummy.next;
    }
    ListNode *swap(ListNode *p1, ListNode *p2) {
        p1->next = p2->next;
        p2->next = p1;
        return p2;
    }

    ListNode *swapPairs_recursive(ListNode *head) {
        if (head==NULL || head->next==NULL)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = head;
        ListNode *next = cur->next;
        cur->next = swapPairs_recursive(next->next);
        next->next = cur;
        dummy.next = next;

        return dummy.next;
    }
};

void print(ListNode *head) {
    while (head) {
            cout << head->val << " ";
            head = head->next;
    }
    cout << endl;
}

ListNode *build_list(const vector<int>& v) {
    ListNode *p = new ListNode(0);
    ListNode *head = p;
    for (size_t i=0; i<v.size(); i++) {
        p->next = new ListNode(v[i]);
        p = p->next;
    }
    return head->next;
}

int main(int argc, char **argv)
{
    int arr[] = {4, 2, 3, 5, 6, 9, 10};
    //int arr[] = {2, 2, 4, 6, 6, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+len);
    ListNode *p = build_list(v);

    print(p);
    Solution sol;
    ListNode *new_list = sol.swapPairs_dummy2(p);
    print(new_list);

    return 0;
}
