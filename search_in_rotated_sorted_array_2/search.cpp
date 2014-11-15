#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n == 0)
            return false;
        int i = n - 1;
        while (i>0 && A[i]==A[0])
            i--;
        int pos = searchUniq(A, i+1, target);
        return pos!=-1;
    }
private:
    int searchUniq(int A[], int n, int target) {
        int pivot = searchPivot(A, n);
        if (pivot == -1) {
            return binarySearch(A, n, target);
        } else {
            if (target > A[n-1]) {
                return binarySearch(A, pivot, target);
            } else {
                int pos = binarySearch(A+pivot, n-pivot, target);
                if (pos == -1)
                    return pos;
                else
                    return pivot + pos;
            }
        }
    }
    int binarySearch(int A[], int n, int target) {
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
        return -1;
	}
    int searchPivot(int A[], int n) {
        if (n == 0)
            return -1;
        int target = A[0];
        int lower = 1;
        int upper = n - 1;
        int ret = -1;
        while (lower <= upper) {
            int mid = lower + (upper-lower)/2;
            if (A[mid] >= target) {
                lower = mid + 1;
            } else {
                ret = mid;
                upper = mid - 1;
            }
        }
        return ret;
    }
};

// sumbit 2 times to accept.
// bug: not consider { 1, 1, 3, 1 }
int main(int argc, char *argv[])
{
    Solution s;
    // int arr[] = { 8, 9, 15, 1, 2, 5 };
    int arr[] = { 1, 1, 3, 1 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int elem = 3;
    int pos = s.search(arr, len, elem);

    cout << "pos:" << pos << endl;
    return 0;
}

