#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
  int sqrt(int x) {
    int min = 0;
    int max = 46340;
    if (x > max*max)
      return max;
    while (min <= max) {
      int middle = int((min+max)/2);
      if (middle*middle == x)
        return middle;
      else if (max-min == 1) {
        if (x == max*max)
          return max;
        else
          return min;
      } else if (middle*middle > x)
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

