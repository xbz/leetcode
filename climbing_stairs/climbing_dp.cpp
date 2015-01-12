#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
        if (n <= 0)
            return 0;

        int f[n+1];
        f[1] = 1;
        f[2] = 2;
        for (int i=3; i<=n; ++i)
            f[i] = f[i-1] + f[i-2];

        return f[n];
    }
};

// sumbit times(for the first accept): 
int main(int argc, char *argv[])
{
    int nStair = atoi(argv[1]);

    Solution s;
    int n = s.climbStairs(nStair);
    cout << n << endl;

    return 0;
}
