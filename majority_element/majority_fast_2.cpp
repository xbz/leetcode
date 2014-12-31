#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int ma_number = 0;
        int ma_n = 0;
        for (size_t i=0; i!=num.size(); ++i) {
            if (ma_n == 0) {
                ma_number = num[i];
                ma_n++;
            } else {
                if (num[i] == ma_number)
                    ma_n++;
                else
                    ma_n--;
            }
        }
        return ma_number;
    }
};

int main(int argc, char **argv)
{
    Solution sol;
    int arr[] = { 1, 4, 1 };
    vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
    int n = sol.majorityElement(v);
    cout << "majority number is:" << n << endl;

    return 0;
}
