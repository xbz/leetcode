#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string s = "1";
    for (int i=1; i<n; i++)
      s = next(s);
    return s;
  }
private:
  string next(const string& s) {
    int count = 1;
    string ret;
    char last = s[0];
    for (size_t i=1; i<s.size(); i++) {
      if (s[i] != last) {
        ret.push_back(count + '0');
        ret.push_back(last);
        count = 1;
      } else
        count++;
      last = s[i];
    }
    ret.push_back(count + '0');
    ret.push_back(last);
    return ret;
  }
};

int main(int argc, char **argv)
{
  int n = atoi(argv[1]);
  Solution sol;
  string s = sol.countAndSay(n);
  cout << "ret:" << s << endl;

  return 0;
}
