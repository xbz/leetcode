#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (size_t i=0; i!=s.size(); ++i)
            ret = ret*26 + (s[i]-'A'+1);

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = "AAA";
    if (argc == 2)
        str = argv[1];

    int ret = s.titleToNumber(str);
    cout << ret << endl;

    return 0;
}

