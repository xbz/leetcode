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
    if (head==NULL)
      return head;

// one poniter solution
    ListNode *cur = head;
    while (cur->next != NULL) {
      if (cur->val == cur->next->val) {
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
      } else
        cur = cur->next;
    }

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
  
  //ListNode t1(1), t2(2), t3(2), t4(4), t5(6), t6(6), t7(8);
  //t1.next = &t2;
  //t2.next = &t3;
  //t3.next = &t4;
  //t4.next = &t5;
  //t5.next = &t6;
  //t6.next = &t7;

  print_list(p);
  Solution sol;
  ListNode *new_list = sol.deleteDuplicates(p);
  print_list(new_list);

  return 0;
}

