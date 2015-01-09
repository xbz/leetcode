#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > f(m+1);
        for (size_t k=0; k<f.size(); ++k)
            f[k].reserve(n+1);

        // int **f = new int* [m];
        // for (int k=0; k<m; ++k) {
        //     f[k] = new int[n];
        //     memset(f[k], 0, n);
        // }

        f[0][0] = 1;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 && j==0)
                    continue;
                if (i!=0)
                    f[i][j] += f[i-1][j];
                if (j!=0)
                    f[i][j] += f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    cout << m << " " << n << endl;
    int sol = s.uniquePaths(m, n);
    cout << "solutions:" << sol << endl;

    return 0;
}

