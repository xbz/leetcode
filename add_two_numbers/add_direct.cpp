#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *l3 = NULL;
    ListNode *p;
    int carry = 0;
    while (l1 || l2 || carry) {
      int sum = carry;
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      carry = sum>=10 ? 1: 0;

      if (!l3)
        l3 = p = new ListNode(sum%10);
      else {
        p->next = new ListNode(sum%10);
        p = p->next;
      }
    }
    return l3;
  }
};

ListNode *gen_num(unsigned long long n)
{
  ListNode *last, *phead;
  int remainder;

  last = NULL;
  phead = NULL;

  if (n == 0) {
    ListNode *pcur = new ListNode(0);
    return pcur;
  }

  while (n > 0) {
    remainder = n % 10;
    n /= 10;
    ListNode *pcur = new ListNode(remainder);
    if (phead == NULL) {
      phead = pcur;
    }

    if (last != NULL) {
      last->next = pcur;
    }
    last = pcur;
  }

  return phead;
}

void print(ListNode *p)
{
  unsigned long long n;
  unsigned long long mag;
  if (p == NULL) {
    return;
  }

  n = 0;
  mag = 1;
  while (p != NULL) {
    n = p->val*mag + n;
    p = p->next;
    mag *= 10;
  }
  cout << "print:" << n << endl;;
}

int main(int argc, char *argv[])
{
//{7,8,8,0,6,5,1,9,9,1}, {8,8,8,1,0,9,7,5,5}
  ListNode *p1, *p2;
  //p1 = gen_num(1991560887);
  //p2 = gen_num(557901888);
  p1 = gen_num(9999999991);
  p2 = gen_num(9);
  //p1 = gen_num(0);
  //p2 = gen_num(0);
  cout << "gen number done" << endl;
  print(p1);
  print(p2);

  Solution sol;
  ListNode *p3 = sol.addTwoNumbers(p1, p2);
  print(p3);

  return 0;
}

