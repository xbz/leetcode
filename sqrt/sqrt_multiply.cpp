#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
  int sqrt(int x) {
    if (x <= 1)
      return x;

    long long low = 0;
    long long high = x;
    while (high-low > 1) {
      long long mid = int((low+high)/2);
      if (mid*mid == x)
        return mid;
      else if (mid*mid > x)
        high = mid;
      else
        low = mid;
    }
    return low;
  }
};

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  Solution s;
  int ret = s.sqrt(n);
  cout << "ret:" << ret << endl;

  return 0;
}

