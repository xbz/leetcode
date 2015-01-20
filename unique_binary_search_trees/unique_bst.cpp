#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int f[n+1];
        f[0] = 1;
        for (int i=1; i<=n; ++i) {
            f[i] = 0;
            for (int j=1; j<=i; ++j)
                f[i] += f[j-1]*f[i-j];
        }
        return f[n];
    }
};

int main(int argc, char *argv[])
{
    int n = 3;
    if (argc == 2)
        n = atoi(argv[1]);

    Solution s;
    int nums = s.numTrees(n);
    cout << "nums: " << nums << endl;
    return 0;
}
