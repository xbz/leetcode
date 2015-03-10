#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0)
            return 0;

        int pos = 0;
        for (int i=1; i<n; i++) {
            if (A[i] != A[pos]) {
                pos++;
				A[pos] = A[i];
            }
        }

        return pos + 1;
    }

    int removeDuplicates_orig(int A[], int n) {
        int i = 0;
        int j = 0;
        while (i < n) {
            if (i>0 && A[i]==A[i-1]) {
                i++;
                while (i<n && A[i]==A[i-1])
                    i++;
            } else {
                A[j] = A[i];
                j++;
                i++;
            }
        }
        return j;
    }

    int removeDuplicates_2(int A[], int n) {
        int j = 0;
        for (int i=0; i<n; i++)
            if (i==0 || A[i]!=A[i-1])
                A[j++] = A[i];

        return j;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    //int arr[] = { 1, 2, 2, 2, 2, 2, 3, 5, 9, 9, 9, 10 };
    //int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    int arr[] = {1, 2, 3, 4};
    //int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int new_len = s.removeDuplicates(arr, len);
    
    cout << "new len:" << new_len << endl;
    for (int i=0; i<new_len; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

