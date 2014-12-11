#include <iostream>

using namespace std;

void print (int A[], int n) {
    for (int i=0; i!=n; ++i)
        cout << A[i] << " ";
    cout << endl;
}

class Solution {
public:
    void sortColors(int A[], int n) {
        int zero_idx = 0;
        int two_idx = n - 1;
        int i = 0;
        while (i <= two_idx) {
            if (A[i] == 0) {
                swap(A, i, zero_idx);
                ++i;
                ++zero_idx;
            } else if (A[i] == 2) {
                swap(A, i, two_idx);
                --two_idx;
            } else {
                ++i;
            }
        }
    }

private:
    void swap(int A[], int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
};

int main(int argc, char* argv[]) {
    int arr[] = { 0, 2 };
    int len = sizeof(arr) / sizeof(arr[0]);
    Solution s;
    print(arr, len);
    s.sortColors(arr, len);
    print(arr, len);

    return 0;
}
