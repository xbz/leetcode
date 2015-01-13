#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        if (A[0] == 0)
            return 0;

        int min_step = 0;
        int cur_max_reach = 0;
        int next_max_reach = 0;
        for (int i=0; i<n; ++i) {
            if (i > cur_max_reach) {
                cur_max_reach = next_max_reach;
                ++min_step;
            }
            next_max_reach = max(next_max_reach, i+A[i]);
        }
        return min_step;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { 2, 3, 1, 2, 3, 4 };
    // int arr[] = { 2 };

    int arrlen = sizeof(arr) / sizeof(arr[0]);
    cout << "arr len:" << arrlen << endl;
    int min_jump = s.jump(arr, arrlen);
    cout << "min_jump:" << min_jump << endl;

    return 0;
}

