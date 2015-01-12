#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        int last = 0;
        for (int i=0; i<n; ++i) {
            if (last < i)
                return false;

            if (i+A[i] > last)
                last = i + A[i];
        }
        return true;
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

