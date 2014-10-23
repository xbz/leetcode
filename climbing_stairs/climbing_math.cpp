#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
        if (n <= 0)
            return 0;

        double x = (sqrt(5)+1.0)/2.0;
        double y = pow(x, n+1)/sqrt(5) + 0.5;

        return int(y);
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
