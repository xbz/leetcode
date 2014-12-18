#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        for (int i=0; i!=32; ++i) {
            int bit = 0;
            for (int j=0; j<n; ++j) {
                bit += (A[j]>>i) & 1;
                bit %= 2;
            }
            ret += bit << i;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = { 1, 3, 4, 5, 6, 90, 90, 1, 3, 5, 6, 4, 20 };
    Solution s;
    int single = s.singleNumber(arr, sizeof(arr)/sizeof(arr[0]));
    cout << single << endl;
    return 0;
}
