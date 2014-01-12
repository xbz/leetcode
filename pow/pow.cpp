#include <iostream>

using namespace std;

class Solution {
public:
  double pow(double x, int n) {
    if (n == 0)
      return 1;
    if (x == 1.0)
      return x;
    if (x == -1.0)
      return (n%2==0) ? 1.0 : -1.0;

    int sign = 1;
    if (n < 0) {
      sign = -1;
      n = -n;
    }
    
    double ret = 1.0;
    for (int i=0; i<n; i++) {
      ret *= x;
      if (ret == 0.0)
        break;
    }

    if (sign == -1)
      return 1.0/ret;
    else
      return ret;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.pow(0.00001, 2147483647) << endl;
  cout << s.pow(1.0,     2147483647) << endl;
  cout << s.pow(-1.0,    2147483647) << endl;
  cout << s.pow(2,       10)         << endl;

  return 0;
}

