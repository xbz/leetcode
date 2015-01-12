#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();

        int f[m][n];
        f[0][0] = grid[0][0];

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 && j==0)
                    continue;

                if (i == 0)
                    f[i][j] = f[i][j-1] + grid[i][j];
                else if (j == 0)
                    f[i][j] = f[i-1][j] + grid[i][j];
                else
                    f[i][j] = min(f[i][j-1], f[i-1][j]) + grid[i][j];
            }
        }
        return f[m-1][n-1];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr1[] = { 0, 0, 2, 1 };
    vector<int> v1(arr1, arr1+sizeof(arr1)/sizeof(arr1[0]));
    int arr2[] = { 3, 5, 4, 6 };
    vector<int> v2(arr2, arr2+sizeof(arr2)/sizeof(arr2[0]));
    int arr3[] = { 0, 2, 0, 0 };
    vector<int> v3(arr3, arr3+sizeof(arr3)/sizeof(arr3[0]));
    vector<vector<int> > grid;
    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);

    int min_sum = s.minPathSum(grid);
    cout << "min sum:" << min_sum << endl;

    return 0;
}

