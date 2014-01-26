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

