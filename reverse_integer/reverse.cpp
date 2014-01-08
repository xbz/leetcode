#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int sign = 1;
    if (x < 0) {
      sign = -1;
      x = -x;
    }

    vector<int> v;
    while (x > 0) {
      v.push_back(x%10);
      x /= 10;
    }

    int d = 0;
    for (size_t i=0; i<v.size(); ++i)
      d = d*10 + v[i];

    return d*sign;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  int d1 = s.reverse(10000);
  int d2 = s.reverse(-7890);

  cout << d1 << endl;
  cout << d2 << endl;

  return 0;
}

