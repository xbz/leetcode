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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0)
            return head;
        if (head==NULL || head->next==NULL)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy;
        ListNode *slow = &dummy;
        for (int i=0; i<k; ++i) {
            if (fast->next == NULL) {
                fast = &dummy;
                k = k % i;
                for (int i=0; i<k; ++i)
                    fast = fast->next;
                break;
            }
            fast = fast->next;
        }

        // k%len == 0
        if (fast->next == NULL)
            return head;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = dummy.next;
        dummy.next = slow->next;
        slow->next = NULL;
        return dummy.next;
    }

    ListNode *rotateRight_orig(ListNode *head, int k) {
        if (k == 0)
            return head;
        if (head==NULL || head->next==NULL)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        int len = 0;
        ListNode *last = NULL;
        while (head != NULL) {
            len += 1;
            last = head;
            head = head->next;
        }

        int n = k % len;
        if (n == 0)
            return dummy.next;

        ListNode *split = &dummy;
        for (int i=0; i<len-n; ++i)
            split = split->next;

        last->next = dummy.next;
        dummy.next = split->next;
        split->next = NULL;
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
    int arr[] = {1, 3, 5, 7};
    //int arr[] = {2, 2, 4, 6, 6, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+len);
    ListNode *p = build_list(v);

    print(p);
    Solution sol;
    int n = 2;
    if (argc == 2)
        n = atoi(argv[1]);

    ListNode *new_list = sol.rotateRight(p, n);
    print(new_list);

    return 0;
}
