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
    unsigned long long n1 = list2num(l1);
    unsigned long long n2 = list2num(l2);
    unsigned long long sum = n1 + n2;
    return num2list(sum);  
  }
private:
  unsigned long long list2num(ListNode *l) {
    unsigned long long n = 0;
    unsigned long long mag = 1;
    while (l) {
      n = n + l->val*mag;
      l = l->next;
      mag *= 10;
    }
    return n;
  }
  ListNode *num2list(unsigned long long n) {
    if (n == 0)
      return new ListNode(0);

    ListNode *head = NULL;
    ListNode *p;
    while (n > 0) {
      if (head == NULL)
        head = p = new ListNode(n%10);
      else {
        p->next = new ListNode(n%10);
        p = p->next;
      }
      n /= 10;
    }
    return head;
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
  p1 = gen_num(0);
  p2 = gen_num(0);
  cout << "gen number done" << endl;
  print(p1);
  print(p2);

  Solution sol;
  ListNode *p3 = sol.addTwoNumbers(p1, p2);
  print(p3);

  return 0;
}

