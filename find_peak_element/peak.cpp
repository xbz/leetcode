#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& v)
{
    vector<int>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() == 1)
            return 0;
        if (num[0] > num[1])
            return 0;
        if (num[num.size()-1] > num[num.size()-2])
            return num.size() - 1;

        int left = 0;
        int right = num.size() - 1;
        while (left < right) {
            int mid = (left+right) / 2;
            if (num[mid]>num[mid-1] && num[mid]>num[mid+1])
                return mid;
            if (num[mid] <= num[mid+1])
                left = mid;
            else
                right = mid;
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
    // int arr[] = { 3, 4, 6, 9, 12, 20, 15, 6 };
    int arr[] = { 3, 4, 5, 2 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    int peak = s.findPeakElement(v);
    print(v);
    cout << "peak:" << peak << endl;

    return 0;
}

