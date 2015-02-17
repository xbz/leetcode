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
    // using 2 lists
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(0);
        ListNode *l2 = head;
        while (l2 != NULL) {
            ListNode *cur = l2;
            l2 = l2->next;
            ListNode *p;
            for (p=&dummy; p->next!=NULL; p=p->next) {
                if (cur->val < p->next->val)
                    break;
            }
            cur->next = p->next;
            p->next = cur;
        }
        return dummy.next;
    }

    ListNode *insertionSortList_orig2(ListNode *head) {
        if (head==NULL)
            return head;

        ListNode *cur = head->next;
        ListNode *pre = head;
        ListNode dummy(0);
        dummy.next = head;
        while (cur != NULL) {
            for (ListNode *p=&dummy; p->next!=cur; p=p->next) {
                if (cur->val < p->next->val) {
                    pre->next = cur->next;

                    cur->next = p->next;
                    p->next = cur;

                    cur = pre;
                    break;
                }
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }

    ListNode *insertionSortList_orig(ListNode *head) {
        if (head==NULL)
            return head;

        ListNode *cur_i = head->next;
        ListNode *pre_i = head;
        ListNode dummy(0);
        dummy.next = head;
        while (cur_i != NULL) {
            ListNode *cur_j = dummy.next;
            ListNode *pre_j = &dummy;
            while (cur_j != cur_i) {
                if (cur_i->val < cur_j->val) {
                    pre_i->next = cur_i->next;
                    pre_j->next = cur_i;
                    cur_i->next = cur_j;

                    cur_i = pre_i;
                    break;
                }
                pre_j = cur_j;
                cur_j = cur_j->next;
            }
            pre_i = cur_i;
            cur_i = cur_i->next;
        }
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
    int arr[] = {10, 5};
    //int arr[] = {2, 2, 4, 6, 6, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+len);
    ListNode *p = build_list(v);

    print(p);
    Solution sol;
    ListNode *new_list = sol.insertionSortList(p);
    print(new_list);

    return 0;
}
