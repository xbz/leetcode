#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
      int pos = 0;
      for (int i=0; i<n; i++) {
        if (A[i] != elem) {
          if (i != pos)
            A[pos] = A[i];
          pos++;
        }
      }

      return pos;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  //int arr[] = { 1, 2, 3, 2, 5, 2, 2, 2, 9 };
  //int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
  int arr[] = {};
  //int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
  int len = sizeof(arr) / sizeof(arr[0]);
  int elem = 2;
  int new_len = s.removeElement(arr, len, elem);
  
  cout << "new len:" << new_len << endl;
  for (int i=0; i<new_len; ++i)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}

