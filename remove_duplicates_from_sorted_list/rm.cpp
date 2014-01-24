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
    for (ListNode *p=head->next; p!=NULL; p=p->next)
      if (p->val != newlast->val) {
        newlast->next = p;
        newlast = newlast->next;
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
  ListNode t1(1), t2(2), t3(2), t4(4), t5(6), t6(6), t7(8);
  t1.next = &t2;
  t2.next = &t3;
  t3.next = &t4;
  t4.next = &t5;
  t5.next = &t6;
  t6.next = &t7;

  print_list(&t1);
  Solution sol;
  ListNode *new_list = sol.deleteDuplicates(&t1);
  print_list(new_list);

  return 0;
}

