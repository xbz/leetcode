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
        int peak = -1;
        for (size_t i=0; i<num.size(); ++i) {
            if (i>0 && num[i]<=num[i-1])
                continue;
            if (i<num.size()-1 && num[i]<=num[i+1])
                continue;

            return i;
        }
        return peak;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = { 5, 4, 6, 9, 1, 20, 15, 6 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    int peak = s.findPeakElement(v);
    print(v);
    cout << "peak:" << peak << endl;

    return 0;
}

