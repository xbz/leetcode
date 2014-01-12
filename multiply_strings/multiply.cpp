#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string ret;
    int mag = 0;
    for (size_t i=0; i<num2.size(); i++) {
      string m = mul(num1, num2[i], mag);
      ret = add(ret, m);
      mag++;
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }
private:
  string add(const string& n1, const string& n2) {
    string ret;
    int carry = 0;
    size_t i = 0;
    size_t j = 0;
    while (i<n1.size() || j<n2.size() || carry) {
      int sum = carry;
      if (i<n1.size()) {
        sum += n1[i]-'0';
        i++;
      }
      if (j<n2.size()) {
        sum += n2[j]-'0';
        j++;
      }

      ret.push_back(sum%10+'0');
      carry = sum/10;
    }
    return ret;
  }
  string mul(const string& n, char ch, int mag) {
    if (ch == '0')
      return "0";
    if (n == "0")
      return "0";

    string s = n;
    while (mag-- > 0)
      s = "0" + s;

    int carry = 0;
    for (size_t i=0; i<s.size(); i++) {
      int ret = (s[i]-'0') * (ch-'0') + carry;
      s[i] = ret%10 + '0';
      carry = ret/10;
    }
    if (carry > 0)
      s.push_back(carry + '0');
    return s;
  }
};

int main(int argc, char *argv[])
{
  char *s1 = argv[1];
  char *s2 = argv[2];
  int n1 = atoi(s1);
  int n2 = atoi(s2);
  Solution s;
  //string ret = s.multiply(s1, s2);
  string ret = s.multiply("498828660196", "840477629533");
  cout << n1 << " " << n2 << " " << n1*n2 << endl;
  cout << ret << endl;

  return 0;
}

