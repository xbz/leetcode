#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int max_subarr = INT_MIN;
        for (int i=0; i<n; ++i) {
            sum += A[i];
            max_subarr = max(max_subarr, sum);
            if (sum < 0)
                sum = 0;
        }
        return max_subarr;
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
