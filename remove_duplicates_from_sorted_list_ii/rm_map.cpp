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
  //int arr[] = {2, 2, 4, 6, 6, 8};
  int arr[] = {2, 2, 2, 2, 2, 2};
  int len = sizeof(arr) / sizeof(arr[0]);
  vector<int> v(arr, arr+len);
  ListNode *p = build_list(v);

  print_list(p);
  Solution sol;
  ListNode *new_list = sol.deleteDuplicates(p);
  print_list(new_list);

  return 0;
}

