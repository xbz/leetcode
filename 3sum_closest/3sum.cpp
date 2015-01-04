#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

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
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int min_diff = INT_MAX;
        int ret = 0;
        for (size_t i=0; i<num.size(); ++i) {
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                int diff = abs(sum - target);
                if (diff < min_diff) {
                    min_diff = diff;
                    ret = sum;
                }
                if (sum == target)
                    return target;
                else if (sum < target)
                    j++;
                else
                    k--;
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    int arr[] = { 0, 4, 3, 0 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution s;
    int target = 10;
    int ret = s.threeSumClosest(v, target);
    cout << "ret:" << ret << endl;

    return 0;
}

