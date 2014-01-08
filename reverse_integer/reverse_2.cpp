#include <iostream>
#include <assert.h>
#include <limits.h>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int sign = 1;
    if (x < 0) {
      x = -x;
      sign = -1;
    }

    long long d = 0;
    while (x > 0) {
      d = d*10 + x%10;
      x /= 10;
    }

    assert(d>=INT_MIN && d<=INT_MAX);
    return d*sign;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  int d1 = s.reverse(-7890);
  cout << d1 << endl;

  int d2 = s.reverse(2147483647);
  cout << d2 << endl;

  return 0;
}

