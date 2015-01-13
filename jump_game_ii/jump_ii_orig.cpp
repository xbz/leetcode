#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        if (A[0] == 0)
            return 0;

        int f[n];
        f[0] = 0;

        int cur = -1;
        int pre = 0;
        for (int j=0; j<n; ++j) {
            int step = f[j] + 1;
            int pos = cur;
            if (pos == -1)
                pos = pre;
            pre = cur;

            for (int k=pos+1; k<=j+A[j]; ++k) {
                if (k == n-1)
                    return step;
                f[k] = step;
                cur = k;
            }
        }
        return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { 2, 3, 1, 1, 4 };
    // int arr[] = { 2 };

    int arrlen = sizeof(arr) / sizeof(arr[0]);
    cout << arrlen << endl;
    int min_jump = s.jump(arr, arrlen);
    cout << "min_jump:" << min_jump << endl;

    return 0;
}

