#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int last = strlen(s)-1;
        while (last>=0 && s[last]==' ')
            last--;

        int len = 0;
        for (; last>=0 && s[last]!=' '; last--)
            len++;

        return len;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  const char *str = "abc defghi";
  int len = s.lengthOfLastWord(str);

  cout << "len:" << len << endl;

  return 0;
}

