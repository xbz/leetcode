#include <iostream>

using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    int i,j;
    int ret;
    ret = 0;
    for (i=0; i<32; i++) {
      int sum = 0;
      for (j=0; j<n; j++) {
        sum += (A[j]>>i) & 1;
      }
      //printf("i:%d j:%d sum%%3:%d\n", i, j, sum%3);
      ret += (sum%3) << i;
    }
    return ret;
  }
};

int main(int argc, char *argv[])
{
  int arr[] = { 1, 90, 4, 1, 5, 6, 4, 90, 5, 90, 1, 6, 5, 6, 4, 88 };
  Solution s;
  int single = s.singleNumber(arr, sizeof(arr)/sizeof(arr[0]));
  cout << single << endl;
  return 0;
}
