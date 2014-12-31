#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int ma_number = 0;
        int ma_n = 0;
        bool ma_empty = true;
        for (size_t i=0; i!=num.size(); ++i) {
            if (ma_empty) {
                ma_number = num[i];
                ma_n = 1;
                ma_empty = false;
            } else {
                if (num[i] == ma_number)
                    ma_n++;
                else {
                    ma_n--;
                    if (ma_n == 0)
                        ma_empty = true;
                }
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
