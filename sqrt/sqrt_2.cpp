#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
  int sqrt(int x) {
    int min = 0;
    int max = x;
    if (x == 0)
      return 0;
    while (min <= max) {
      if (max-min == 1) {
        if (max == x/max)
          return max;
        else
          return min;
      }

      int middle = int((min+max)/2);
      if (middle == x/middle)
        return middle;
      else if (middle > x/middle)
        max = middle;
      else
        min = middle;
    }
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

