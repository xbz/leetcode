#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> v;
        v.push_back("M");
        v.push_back("CM");
        v.push_back("D");
        v.push_back("CD");
        v.push_back("C");
        v.push_back("XC");
        v.push_back("L");
        v.push_back("XL");
        v.push_back("X");
        v.push_back("IX");
        v.push_back("V");
        v.push_back("IV");
        v.push_back("I");

        int i=0;
        string s;
        while (num>0) {
            int times = num/n[i];
            num -= n[i]*times;
            for (; times>0; --times)
                s += v[i];
            i++;
        }

        return s;
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
