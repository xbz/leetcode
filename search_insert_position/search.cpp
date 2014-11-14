#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int lower = 0;
        int upper = n - 1;
        while (lower <= upper) {
            int mid = lower + (upper-lower)/2;
            if (A[mid] > target)
                upper = mid - 1;
            else if (A[mid] < target)
                lower = mid + 1;
            else
                return mid;
        }
        // can't find target
        lower = 0;
        upper = n - 1;
        // int ret = -1; is a bug
        int ret = n;
        while (lower <= upper) {
            int mid = lower + (upper-lower)/2;
            if (A[mid] > target) {
                ret = mid;
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }
        return ret;
    }
};

// sumbit 3 times to accept.
int main(int argc, char *argv[])
{
    Solution s;
    int arr[] = { 2, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int elem = 8;
    int pos = s.searchInsert(arr, len, elem);

    cout << "pos:" << pos << endl;
    return 0;
}

