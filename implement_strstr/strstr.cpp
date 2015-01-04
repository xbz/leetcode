#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int pos = 0;
        int limit = string_len(haystack) - string_len(needle);
        while (pos <= limit) {
            int cmp = str_start_contain(&haystack[pos], needle);
            if (cmp == 0)
                return pos;
            pos++;
        }
        return -1;
    }

private:
    int string_len(char *s) {
        int len = 0;
        while (*s) {
            ++len;
            ++s;
        }
        return len;
    }

    int str_start_contain(char *s1, char *s2) {
        while (*s1 && *s2) {
            if (*s1 != *s2)
                return *s1 - *s2;
            ++s1;
            ++s2;
        }
        if (*s2)
            return *s2;
        return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    char haystack[] = "hello world";
    char needle[] = "world";
    int pos = s.strStr(haystack, needle);
    cout << "pos:" << pos << endl;

    return 0;
}

