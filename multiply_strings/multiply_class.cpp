#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Num {
public:
  Num() {
    _num = "";
  }
  Num(char *s) {
    _num = string(s);
  }
  Num(const string& s) {
    _num = s;
    reverse(_num.begin(), _num.end());
  }
  Num(const Num& n) {
    _num = n.str();
  }
  size_t size() const {
    return _num.size();
  }
  string str() const {
    return _num;
  }
  char operator[](int i) const {
    return _num[i];
  }
  void push(char ch) {
    _num.push_back(ch);
  }
  void set(int i, char ch) {
    _num[i] = ch;
  }
  void mul10() {
    _num = string("0") + _num;
  }
  string digits() const {
    string s = _num;
    reverse(s.begin(), s.end());
    return s;
  }
  bool operator==(const Num& n) const {
    return _num == n.str();
  }
  friend Num operator+(const Num& n1, const Num& n2);
  friend Num operator*(const Num& n1, const Num& n2);
private:
  string _num;
};

Num operator+(const Num& n1, const Num& n2)
{
  Num ret;
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

    ret.push(sum%10+'0');
    carry = sum/10;
  }
  return ret;
}

Num operator*(const Num& n1, const Num& n2)
{
    Num ret;
    int mag = 0;
    for (size_t i=0; i<n2.size(); i++) {
      Num m;
      if (n2[i] == '0')
        m = string("0");
      else if (n1 == string("0"))
        m = string("0");
      else {
        Num s = n1;
        int tmpmag = mag;
        while (tmpmag-- > 0)
          s.mul10();

        int carry = 0;
        for (size_t j=0; j<s.size(); j++) {
          int ret = (s[j]-'0') * (n2[i]-'0') + carry;
          s.set(j, ret%10 + '0');
          carry = ret/10;
        }
        if (carry > 0)
          s.push(carry + '0');
        m = s;
      }

      ret = ret + m;
      mag++;
    }
    return ret;
}

class Solution {
public:
  string multiply(string num1, string num2) {
    Num n1(num1);
    Num n2(num2);

    Num ret = n1*n2;
    return ret.digits();
  }
};

int main(int argc, char *argv[])
{
  char *s1 = argv[1];
  char *s2 = argv[2];
  int n1 = atoi(s1);
  int n2 = atoi(s2);
  Solution s;
  string ret = s.multiply(s1, s2);
  //string ret = s.multiply("498828660196", "840477629533");
  cout << n1 << " " << n2 << " " << n1*n2 << endl;
  cout << ret << endl;

  return 0;
}

