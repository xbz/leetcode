#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // run time complexity is O(m+n), NOT O(log (m+n))!
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int fasti = 0;
        int fastj = 0;
        int slowi = 0;
        int slowj = 0;
        int slow_value;
        while (fasti<m || fastj<n) {
            int fast_value;
            move(A, m, B, n, 2, fasti, fastj, fast_value);
            move(A, m, B, n, 1, slowi, slowj, slow_value);
        }
        int next;
        move(A, m, B, n, 1, slowi, slowj, next);

        if ((m+n)%2 == 0)
            return (slow_value+next) / 2.0;
        else
            return slow_value;
    }

private:
    void move(int A[], int m, int B[], int n, int step,
              int &i, int &j, int &value) {
        while (i<m && j<n && step>0) {
            if (A[i] <= B[j]) {
                value = A[i];
                i++;
            } else {
                value = B[j];
                j++;
            }
            step--;
        }
        while (i<m && step>0) {
            value = A[i];
            i++;
            step--;
        }
        while (j<n && step>0) {
            value = B[j];
            j++;
            step--;
        }
    }

};

int main(int argc, char *argv[])
{
    Solution s;
    int A[] = {1};
    int len_a = sizeof(A) / sizeof(A[0]);
    int B[] = {};
    int len_b = sizeof(B) / sizeof(int);
    double median = s.findMedianSortedArrays(A, len_a, B, len_b);
    cout << median << endl;

    return 0;
}
