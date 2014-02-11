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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL)
      return head;

    ListNode *ret = new ListNode(0);
    ret->next = head;
    ListNode *cur = head;
    ListNode *pre = ret;
    while (cur) {
      if (cur->next && cur->val!=cur->next->val) {
        pre = cur;
        cur = cur->next;
        continue;
      }

      if (cur->next == NULL) {
        pre->next = cur;
        cur = cur->next;
      } else {
        int val = cur->val;
        while (cur && cur->val==val) {
          ListNode *del = cur;
          cur = cur->next;
          delete del;
        }
        pre->next = cur;
      }
    }

    return ret->next;
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
