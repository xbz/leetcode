#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        while (m>0 && n>0) {
            if (B[n-1] > A[m-1]) {
                A[m+n-1] = B[n-1];
                n--;
            } else {
                A[m+n-1] = A[m-1];
                m--;
            }
        }
        while (n > 0) {
            A[n-1] = B[n-1];
            n--;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int arr1[6] = { 12, 13, 15 };
    int len1 = 3;
    int arr2[] = { 9, 10, 11 };
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    s.merge(arr1, len1, arr2, len2);

    for (size_t i=0; i<sizeof(arr1)/sizeof(arr1[0]); ++i)
        cout << arr1[i] << " ";
    cout << endl;
    return 0;
}

