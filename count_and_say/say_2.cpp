#include <iostream>
#include <string>
#include <sstream>
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
    ostringstream ss;
    size_t i = 0;
    while (i < s.size()) {
      size_t j = i + 1;
      while (j<s.size() && s[i]==s[j])
        j++;
      ss << j-i << s[i];
      i = j;
    }
    return ss.str();
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
