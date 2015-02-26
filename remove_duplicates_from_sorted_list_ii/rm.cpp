#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;

        while (pre->next!=NULL && pre->next->next!=NULL) {
            if (pre->next->val == pre->next->next->val) {
                int val = pre->next->val;
                while (pre->next!=NULL && pre->next->val==val)
                    pre->next = pre->next->next;
            } else
                pre = pre->next;
        }
        return dummy.next;
    }

    ListNode *deleteDuplicates_cur_pre(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while (cur != NULL) {
            while (cur->next!=NULL && cur->val==cur->next->val)
                cur = cur->next;
            if (pre->next == cur)
                pre = cur;
            else
                pre->next = cur->next;
            cur = cur->next;
        }
        return dummy.next;
    }

    ListNode *deleteDuplicates_orig(ListNode *head) {
        if (head == NULL)
            return head;

        ListNode *pp = new ListNode(0);
        pp->next = head;
        ListNode *prehead = pp;
        bool dup = false;
        while (head->next) {
            if (head->val == head->next->val) {
                ListNode *tmp = head;
                head = head->next;
                delete tmp;
                dup = true;
            } else {
                if (dup)
                    pp->next = head->next;
                else
                    pp = pp->next;
                dup = false;
                head = head->next;
            }
        }
        if (dup)
            pp->next = NULL;
        return prehead->next;
    }

    ListNode *deleteDuplicates_direct(ListNode *head) {
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *ret = pre;
        ListNode *cur = head;
        while (cur) {
            while (cur->next!=NULL && cur->val==cur->next->val)
                cur = cur->next;
            if (pre->next == cur)
                pre = cur;
            else
                pre->next = cur->next;
            cur = cur->next;
        }
        return ret->next;
    }

    ListNode *deleteDuplicates_map(ListNode *head) {
        map<int, int> m;
        while (head) {
            m[head->val]++;
            head = head->next;
        }

        ListNode *p = new ListNode(0);
        ListNode *newhead = p;
        for (map<int, int>::iterator it=m.begin(); it!=m.end(); ++it) {
            if (it->second > 1)
                continue;
            p->next = new ListNode(it->first);
            p = p->next;
        }
        return newhead->next;
    }
};

void print_list(ListNode *head) {
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
    int arr[] = {1, 2, 2, 4, 6, 6, 8};
    //int arr[] = {2, 2, 4, 6, 6, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+len);
    ListNode *p = build_list(v);

    print_list(p);
    Solution sol;
    ListNode *new_list = sol.deleteDuplicates(p);
    print_list(new_list);

    return 0;
}

