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
        cout << head->val << " ";
        head =  head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
		ListNode *p = &dummy;
        while (p->next != NULL)
            p = p->next;

        quicksort(head, p);
        return head;
    }
private:
    void swap(ListNode *p1, ListNode *p2) {
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }

    // pair<ListNode *, ListNode *> partition(ListNode *head, ListNode *tail) {
    ListNode *partition(ListNode *head, ListNode *tail) {
        int pivot = head->val;
        swap(head, tail);

        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        ListNode *pPos = head;
        ListNode *pPrePos = &dummy;
        while (p->next != NULL && p->next->next!=NULL) {
            if (p->next->val < pivot) {
                swap(pPos, p->next);
                pPrePos = pPos;
                pPos = pPos->next;
            }
            p = p->next;
        }
        swap(pPos, tail);
        // return make_pair(pPos, pPrePos);
        return pPrePos;
    }

    void quicksort(ListNode *head, ListNode *tail) {
        if (head==NULL || tail==NULL || head==tail || tail->next==head)
            return;

        // pair<ListNode *, ListNode *> p = partition(head, tail);
        // ListNode *pPrePos = p.second;
        ListNode *pPrePos = partition(head, tail);
        quicksort(head, pPrePos);
        quicksort(pPrePos->next->next, tail);
    }
};

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
    int arr[] = {3, 2, 1};
    //int arr[] = {2, 2, 4, 6, 6, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr+len);
    ListNode *p = build_list(v);
    print(p);

    Solution s;
    ListNode *ret = s.sortList(p);
    print(ret);

    return 0;
}
