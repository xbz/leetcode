#include <iostream>

using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    int ret = 0;
    for (int i = 0; i < n; i++)
      ret ^= A[i];
    return ret;
  }
};

int main(int argc, char *argv[])
{
  int arr[] = { 1, 3, 4, 5, 6, 90, 90, 1, 5, 6, 4, 20, 20};
  Solution s;
  int single = s.singleNumber(arr, sizeof(arr)/sizeof(arr[0]));
  cout << single << endl;
  return 0;
}
