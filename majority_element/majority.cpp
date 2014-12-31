#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> m;
        int ma_number = 0;
        int ma_n = 0;
        for (size_t i=0; i!=num.size(); ++i) {
            m[num[i]] += 1;
            if (m[num[i]] > ma_n) {
                ma_n = m[num[i]];
                ma_number = num[i];
            }
        }
        return ma_number;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    int arr[] = { 1, 2, 4, 3, 4, 4, 4 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    int n = sol.majorityElement(v);
    cout << "majority number is:" << n << endl;

    return 0;
}
