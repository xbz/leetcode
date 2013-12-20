#include <iostream>
#include <map>

using namespace std;

enum { FIRST, SECOND };

class Solution {
public:
  int singleNumber(int A[], int n) {
    map<int, int> m;
    map<int, int>::iterator it;
    for (int i = 0; i < n; i++) {
      it = m.find(A[i]);
      if (it == m.end())
        m[A[i]] = FIRST;
      else {
        if (m[A[i]] == FIRST)
          m[A[i]] = SECOND;
        else if (m[A[i]] == SECOND)
          m.erase(it);
      }
    }
    return m.begin()->first;
  }
};

int main(int argc, char *argv[])
{
  int arr[] = { 1, 90, 4, 1, 5, 6, 4, 90, 5, 90, 1, 6, 5, 6, 4, 20 };
  Solution s;
  int single = s.singleNumber(arr, sizeof(arr)/sizeof(arr[0]));
  cout << single << endl;
  return 0;
}
