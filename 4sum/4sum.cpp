#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <map>

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
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;

        sort(num.begin(), num.end());
        for (size_t i=0; i<num.size(); ++i) {
            while (i>0 && i<num.size() && num[i]==num[i-1])
                ++i;

            for (size_t j=i+1; j<num.size(); ++j) {
                while (j>i+1 && j<num.size() && num[j]==num[j-1])
                    ++j;

                size_t m = j + 1;
                size_t n = num.size() - 1;
                while (m < n) {
                    int sum = num[i] + num[j] + num[m] + num[n];
                    if (sum == target) {
                        int arr[] = { num[i], num[j], num[m], num[n] };
                        vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
                        ret.push_back(v);
                        m++;
                        n--;

                        while (m>j+1 && m<n && num[m]==num[m-1])
                            m++;
                        while (n<num.size()-1 && m<n && num[n]==num[n+1])
                            n--;
                    } else if (sum < target)
                        ++m;
                    else
                        --n;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    //int arr[] = { 0, 4, 3, 0 };
    int arr[] = { -1,-5,-5,-3,2,5,0,4 };

    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    int target = -7;
    vector<vector<int> > r = s.fourSum(v, target);
    cout << "done" << endl;
    for (size_t i=0; i<r.size(); i++)
        print(r[i]);

    return 0;
}

