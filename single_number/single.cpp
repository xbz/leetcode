#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    set<int> s;
    for (int i = 0; i < n; i++) {
      if (s.find(A[i]) == s.end())
        s.insert(A[i]);
      else
        s.erase(A[i]);
    }
    return *s.begin();
  }
};

int main(int argc, char *argv[])
{
  int arr[] = { 1, 3, 4, 5, 6, 90, 90, 1, 3, 5, 6, 4, 20 };
  Solution s;
  int single = s.singleNumber(arr, sizeof(arr)/sizeof(arr[0]));
  cout << single << endl;
  return 0;
}
