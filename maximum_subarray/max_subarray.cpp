#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int f[n];
        f[0] = A[0];
        int g[n];
        g[0] = A[0];

        for (int i=1; i<n; ++i) {
            // g[i] = A[i];
            // if (g[i-1] > 0)
            //     g[i] += g[i-1];
            g[i] = max(A[i], g[i-1] + A[i]);
            f[i] = max(f[i-1], g[i]);
        }
        return f[n-1];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = s.maxSubArray(arr, n);
    cout << "max_sum:" << max_sum << endl;

    return 0;
}
