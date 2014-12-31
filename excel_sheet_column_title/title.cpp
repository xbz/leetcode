#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n > 0) {
            char cur = 'A' + (n-1)%26;
            s = cur + s;
            n = (n-1) / 26;
        }

        return s;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int n = 26;
    if (argc == 2)
        n = atoi(argv[1]);

    string str = s.convertToTitle(n);
    cout << str << endl;

    return 0;
}

