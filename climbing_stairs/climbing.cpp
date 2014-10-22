#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int pp = 1;
        int p = 2;
        int sum = 0;
        for (int i=0; i<n-2; ++i) {
            sum = p + pp;
            pp = p;
            p = sum;
        }
        return sum;
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
