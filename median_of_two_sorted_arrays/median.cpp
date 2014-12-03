#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int A[] = {1,3,5};
    int len_a = sizeof(A) / sizeof(A[0]);
    int B[] = {2,4,6};
    int len_b = sizeof(B) / sizeof(B[0]);
    double median = s.findMedianSortedArrays(A, len_a, B, len_b);
    cout << median << endl;

    return 0;
}
