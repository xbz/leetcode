#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
// 1. negative number is NOT palindrome
// 2. pow return double, dont compare double to int
// 3. if x if negtive: x = -x; doesnt work on -2147483648
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        return palin_helper(x, digit_num(x));
    }

private:
    bool palin_helper(int x, int digit) {
        if (digit==0 || digit==1)
            return true;

        if (x/static_cast<int>(pow(10, digit-1)) != x%10)
            return false;

        return palin_helper(x%static_cast<int>(pow(10, digit-1)) / 10, digit-2);
    }

    int digit_num(int x) {
        if (x/1000000000 > 0)
            return 10;
        if (x/100000000 > 0)
            return 9;
        if (x/10000000 > 0)
            return 8;
        if (x/1000000 > 0)
            return 7;
        if (x/100000 > 0)
            return 6;
        if (x/10000 > 0)
            return 5;
        if (x/1000 > 0)
            return 4;
        if (x/100 > 0)
            return 3;
        if (x/10 > 0)
            return 2;
        return 1;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    int n = -2147483648;
    bool isPalin = s.isPalindrome(n);
    cout << "isPalin:" << isPalin << endl;

    return 0;
}
