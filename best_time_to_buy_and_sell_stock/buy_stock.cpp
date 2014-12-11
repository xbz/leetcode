#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(const vector<int>& v)
{
    vector<int>::const_iterator it;
    for (it=v.begin(); it!=v.end(); ++it)
        cout << *it;
    cout << endl;
}

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;

        int max_pro = INT_MIN;
        int max_sell = INT_MIN;
        for (size_t i=prices.size()-1; i!=0; --i) {
            if (prices[i] > max_sell)
                max_sell = prices[i];

            int cur_pro = max_sell - prices[i-1];
            if (cur_pro > max_pro)
                max_pro = cur_pro;
        }
        if (max_pro < 0)
            max_pro = 0;
        return max_pro;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> v;
    v.push_back(14);
    v.push_back(10);
    // v.push_back(7);
    // v.push_back(3);
    // v.push_back(1);
    int max_profit = s.maxProfit(v);
    cout << "max profit:" << max_profit << endl;

    return 0;
}
