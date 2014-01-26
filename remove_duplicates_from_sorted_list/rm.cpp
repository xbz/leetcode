#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head==NULL || head->next==NULL)
      return head;

    ListNode *newlast = head;
    ListNode *p = head->next;
    while (p != NULL)
      if (p->val != newlast->val) {
        newlast->next = p;
        newlast = newlast->next;
        p = p->next;
      } else {
        ListNode *tmp = p;
        p = p->next;
        delete tmp;
      }

    newlast->next = NULL;
    return head;
  }
};

void print_list(ListNode *head) {
  while (head) {
      cout << head->val << " ";
      head = head->next;
  }
  cout << endl;
}

int main(int argc, char **argv)
{
  ListNode *p = new ListNode(1);
  p->next = new ListNode(2);
  p->next->next = new ListNode(2);
  p->next->next->next = new ListNode(4);
  p->next->next->next->next = new ListNode(6);
  p->next->next->next->next->next = new ListNode(6);
  p->next->next->next->next->next->next = new ListNode(8);

  print_list(p);
  Solution sol;
  ListNode *new_list = sol.deleteDuplicates(p);
  print_list(new_list);

  return 0;
}

