#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        if (s[0] == '0')
            return 0;

        int f[n+1];
        f[0] = 1;
        f[1] = 1;
        for (int i=2; i<=n; ++i) {
           if (s[i-1]=='0') {
                if (s[i-2]!='1' && s[i-2]!='2')
                    return 0;

                f[i] = f[i-2];
            } else {
                f[i] = f[i-1];
                if (s[i-2]=='1' || \
                    (s[i-2]=='2' && (s[i-1]>='1'&&s[i-1]<='6')))
                    f[i] += f[i-2];
            }
        }
        return f[n];
    }
};

int main(int argc, char *argv[])
{
    char *s1 = argv[1];
    Solution s;
    int n = s.numDecodings(s1);
    cout << "decode ways:" << n << endl;

    return 0;
}

