#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s;
        int magnitude = 1;
        while (num > 0) {
            int value = num%10;
            s = build(value, magnitude) + s;
            num /= 10;
            magnitude *= 10;
        }
        return s;
    }
private:
    string build(int value, int magnitude) {
        map<int, string> m;
        m[1] = "IVX";
        m[10] = "XLC";
        m[100] = "CDM";
        m[1000] = "M??";

        char one = m[magnitude][0];
        char five = m[magnitude][1];
        char ten = m[magnitude][2];
        if (value == 4)
            return string(1, one) + string(1, five);
        else if (value == 9)
            return string(1, one) + string(1, ten);

        string ret;
        if (value >= 5)
            ret = string(value/5, five);
        return ret + string(value%5, one);
    }
};

// sumbit times(for the first accept):
int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    Solution s;
    string ret = s.intToRoman(n);
    cout << n << " " << ret << endl;

    return 0;
}
