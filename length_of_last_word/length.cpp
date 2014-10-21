#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int start = strlen(s)-1;
        for (; start>=0; start--) {
            if (s[start] != ' ')
                break;
        }

        int len = 0;
        for (int i=start; i>=0; i--) {
            if (s[i] == ' ')
                break;
            len++;
        }
        return len;
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  const char *str = "abc defghi   ";
  int len = s.lengthOfLastWord(str);

  cout << "len:" << len << endl;

  return 0;
}

