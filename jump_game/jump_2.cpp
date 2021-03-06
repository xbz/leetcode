#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 0)
            return false;

        int f[n];
        f[0] = 1;
        for (int i=1; i<n; ++i) {
            f[i] = 0;
            for (int j=i-1; j>=0; j--) {
                if (f[j]!=0 && j+A[j]>=i) {
                    f[i] = 1;
                    break;
                }
            }
        }
        return f[n-1];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { 0, 0, 0, 0, 1 };

    int arrlen = sizeof(arr) / sizeof(arr[0]);
    cout << arrlen << endl;
    bool bJump = s.canJump(arr, arrlen);
    cout << "can jump:" << bJump << endl;

    return 0;
}

