#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = 0;
        for (string::size_type i=0; i<s.size(); ++i) {
            if (s[i] == 'I') {
                if (i+1<s.size() && (s[i+1]=='V' || s[i+1]=='X'))
                    n -= 1;
                else
                    n += 1;
            } else if (s[i] == 'V')
                n += 5;
            else if (s[i] == 'X') {
                if (i+1<s.size() && (s[i+1]=='L' || s[i+1]=='C'))
                    n -= 10;
                else
                    n += 10;
            } else if (s[i] == 'L')
                n += 50;
            else if (s[i] == 'C') {
                if (i+1<s.size() && (s[i+1]=='D' || s[i+1]=='M'))
                    n -= 100;
                else
                    n += 100;
            } else if (s[i] == 'D')
                n += 500;
            else if (s[i] == 'M')
                n += 1000;
        }
        return n;
    }
};

// sumbit times(for the first accept): 1
int main(int argc, char *argv[])
{
    string str = argv[1];
    Solution s;
    int n = s.romanToInt(str);
    cout << str << " " << n << endl;

    return 0;
}
