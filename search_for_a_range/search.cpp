#include <iostream>
#include <vector>

using namespace std;

// template
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int low = 0;
        int high = n - 1;
        while (low+1 < high) {
            int mid = low + (high-low)/2;
            if (A[mid] == target)
                high = mid;
            else if (A[mid] > target)
                high = mid;
            else
                low = mid;
        }

        vector<int> ret(2, -1);
        if (A[low] == target)
            ret[0] = low;
        else if (A[high] == target)
            ret[0] = high;
		else
            return ret;

        low = 0;
        high = n - 1;
        while (low+1 < high) {
            int mid = low + (high-low)/2;
            if (A[mid] == target)
                low = mid;
            else if (A[mid] > target)
                high = mid;
            else
                low = mid;
        }
        if (A[high] == target)
            ret[1] = high;
        else if (A[low] == target)
            ret[1] = low;
        return ret;
    }
};

class Solution_orig {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = searchLower(A, n, target);
        int upper = searchUpper(A, n, target);
        vector<int> v;
        v.push_back(lower);
        v.push_back(upper);
        return v;
    }
private:
    int searchLower(int A[], int n, int target) {
        int lower = 0;
        int upper = n - 1;
        int ret = -1;
        while (lower <= upper) {
            int mid = lower + (upper-lower)/2;
            if (A[mid] < target) {
                lower = mid + 1;
            } else if (A[mid] > target) {
                upper = mid - 1;
            } else {
                ret = mid;
                upper = mid - 1;
            }
        }
        return ret;
    }
    int searchUpper(int A[], int n, int target) {
        int lower = 0;
        int upper = n - 1;
        int ret = -1;
        while (lower <= upper) {
            int mid = lower + (upper-lower)/2;
            if (A[mid] < target) {
                lower = mid + 1;
            } else if (A[mid] > target) {
                upper = mid - 1;
            } else {
                ret = mid;
                lower = mid + 1;
            }
        }
        return ret;
	}
};

int main(int argc, char *argv[])
{
    Solution s;
    //int arr[] = { 1, 2, 3, 2, 5, 2, 2, 2, 9 };
    //int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    //int arr[] = {};
    int arr[] = { 0, 1, 1, 2, 2, 2, 2, 2, 3 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int elem = 1;
    vector<int> v = s.searchRange(arr, len, elem);

    cout << v[0] << " " << v[1] << endl;
    return 0;
}

