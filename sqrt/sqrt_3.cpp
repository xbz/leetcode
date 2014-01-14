#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
  int sqrt(int x) {
    int min = 0;
    int max = x;
    if (x <= 1)
      return x;
    while (max-min > 1) {
      int middle = int((min+max)/2);
      if (middle == x/middle)
        return middle;
      else if (middle > x/middle)
        max = middle;
      else
        min = middle;
    }
    return min;
  }
};

int main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  Solution s;
  int ret = s.sqrt(n);
  cout << "ret:" << ret << endl;

  cout << LONG_MAX << endl;
  cout << LONG_LONG_MAX << endl;
  return 0;
}

