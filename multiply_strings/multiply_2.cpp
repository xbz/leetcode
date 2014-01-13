#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

void print(const vector<int>& v)
{
  vector<int>::const_iterator it;
  for (it=v.begin(); it!=v.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

class Solution {
public:
  string multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int len1 = int(num1.size());
    int len2 = int(num2.size());
    vector<int> ret(len1+len2, 0);
    for (int i=0; i<len1; i++) {
      int carry = 0;
      for (int j=0; j<len2; j++) {
        int sum = carry + (num1[i]-'0')*(num2[j]-'0') + ret[i+j];
        carry = sum/10;
        ret[i+j] = sum%10;
      }
      ret[i+len2] = carry;
    }

    int i;
    for (i=ret.size()-1; i>0 && ret[i]==0; i--)
      ;
    string s;
    for (int j=i; j>=0; j--)
      s.push_back(ret[j]+'0');

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
  string ret = s.multiply(s1, s2);
  cout << n1 << " " << n2 << " " << n1*n2 << endl;
  cout << ret << endl;
  ret = s.multiply("498828660196", "840477629533");
  cout << ret << endl;

  return 0;
}

