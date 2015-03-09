#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if (n == 0)
			return 0;

		int pos = 0;
		int cp_cnt = 1;
		const int COPY_LIMIT = 2;
		for (int i=1; i<n; i++) {
			if (A[i] != A[pos]) {
				cp_cnt = 1;
				pos++;
				A[pos] = A[i];
			} else {
				if (cp_cnt < COPY_LIMIT) {
					cp_cnt++;
					pos++;
					A[pos] = A[i];
				}
			}
		}
		return pos+1;
	}

    int removeDuplicates_orig(int A[], int n) {
        if (n <= 1)
            return n;

        int count = 1;
        int j = 1;
        for (int i=1; i<n; i++)
            if (A[i]!=A[i-1]) {
                count = 1;
                A[j++] = A[i];
            } else {
                count++;
                if (count > 2)
                    continue;
                A[j++] = A[i];
            }

        return j;
    }

    int removeDuplicates_2(int A[], int n) {
        if (n <= 2)
            return n;

        int j = 2;
        for (int i=2; i<n; i++)
            if (A[i]!=A[j-2])
                A[j++] = A[i];

        return j;
    }

    int removeDuplicates_3(int A[], int n) {
        if (n <= 2)
            return n;

        int j = 2;
        for (int i=2; i<n; i++) {
            if (A[i]==A[j-1] && A[i]==A[j-2])
                continue;
            A[j++] = A[i];
        }
        return j;
    }

    int removeDuplicates_flag(int A[], int n) {
        if (n <= 1)
            return n;

        bool first = true;
        int j = 1;
        for (int i=1; i<n; i++)
            if (A[i]!=A[i-1]) {
                A[j++] = A[i];
                first = true;
            } else if (first) {
                A[j++] = A[i];
                first = false;
            }

        return j;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    //int arr[] = { 1, 2, 2, 2, 2, 2, 3, 5, 9, 9, 9, 10 };
    //int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    //int arr[] = {1, 2, 3, 4};
    //int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    int arr[] = { 1, 1 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int new_len = s.removeDuplicates(arr, len);
    
    cout << "new len:" << new_len << endl;
    for (int i=0; i<new_len; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

