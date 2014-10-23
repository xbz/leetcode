#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
	    m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int n = 0;
        for (string::size_type i=0; i<s.size(); ++i) {
            if (i+1<s.size() && m[s[i]]<m[s[i+1]])
                n -= m[s[i]];
            else
                n += m[s[i]];
        }
        return n;
    }
};

// sumbit times(for the first accept):
int main(int argc, char *argv[])
{
    string str = argv[1];
    Solution s;
    int n = s.romanToInt(str);
    cout << str << " " << n << endl;

    return 0;
}
