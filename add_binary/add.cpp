#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int carry = 0;
    string ret;
    int sum;
    int i = a.size()-1;
    int j = b.size()-1;
    while (i>=0 || j>=0 || carry) {
      sum = carry;
      if (i>=0) {
        sum += a[i]-'0';
        i--;
      }
      if (j>=0) {
        sum += b[j]-'0';
        j--;
      }
      carry = sum>=2 ? 1 : 0;
      ostringstream ss;
      ss << sum%2;
      ret = ss.str() + ret;
    }
    return ret;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;
  string a = "111111111111";
  string b = "1";
  string s = sol.addBinary(a, b);
  cout << s << endl;

  return 0;
}

