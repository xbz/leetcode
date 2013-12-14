#include <iostream>

using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    for (int i = 1; i < n; i++)
      A[0] ^= A[i];
    return A[0];
  }
};

int main(int argc, char *argv[])
{
  int arr[] = { 1, 4, 5, 90, 90, 1, 5, 6, 4, 20, 20};
  Solution s;
  int single = s.singleNumber(arr, sizeof(arr)/sizeof(arr[0]));
  cout << single << endl;
  return 0;
}
