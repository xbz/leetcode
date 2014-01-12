#include <iostream>

using namespace std;

class Solution {
public:
  double pow(double x, int n) {
    if (x == 1.0)
      return x;

    int sign = 1;
    if (n < 0) {
      sign = -1;
      n = -n;
    }

    double ret = power(x, n);
    if (sign == -1)
      return 1.0/ret;
    else
      return ret;
  }
private:
  double power(double x, int n) {
    if (n == 0)
      return 1.0;

    double d = power(x, n/2);
    if (n%2 == 1)
      return d*d*x;
    else
      return d*d;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  cout << s.pow(1,      -2147483648) << endl;
  cout << s.pow(2,       10)         << endl;
  cout << s.pow(0.00001, 2147483647) << endl;
  cout << s.pow(1.0,     2147483647) << endl;
  cout << s.pow(-1.0,    2147483647) << endl;

  return 0;
}

