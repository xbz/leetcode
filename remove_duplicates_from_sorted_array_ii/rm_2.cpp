#include <iostream>

using namespace std;

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if (n <= 2)
      return n;

    int j = 2;
    for (int i=2; i<n; i++)
      if (A[i]!=A[j-2])
        A[j++] = A[i];

    return j;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  //int arr[] = { 1, 2, 2, 2, 2, 2, 3, 5, 9, 9, 9, 10 };
  int arr[] = { 1, 1, 1, 2, 2, 10 };
  //int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
  //int arr[] = {1, 2, 3, 4};
  //int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
  //int arr[] = { 1, 1 };
  int len = sizeof(arr) / sizeof(arr[0]);
  int new_len = s.removeDuplicates(arr, len);
  
  cout << "new len:" << new_len << endl;
  for (int i=0; i<new_len; ++i)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}

