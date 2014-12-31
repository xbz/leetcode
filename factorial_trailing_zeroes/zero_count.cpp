#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            n /= 5;
            count += n;
        }

        return count;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int n = 26;
    if (argc == 2)
        n = atoi(argv[1]);

    int zero_count = s.trailingZeroes(n);
    cout << zero_count << endl;

    return 0;
}

